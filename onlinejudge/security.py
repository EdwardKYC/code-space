# bruteforce_key_search.py
# Usage:
#  python bruteforce_key_search.py --b64 "<BASE64>" --mask "?Y5?V9C96L?X8?8u" --charset all
#  python bruteforce_key_search.py --b64 "<BASE64>" --length 8 --charset alnum
# Notes:
#  - This script uses raw key (utf-8) -> zero-pad to 16 bytes -> AES-ECB decrypt -> rstrip zero bytes -> utf-8 decode
#  - It only accepts results that look like human-readable sentences by default; use --accept-any-utf8 to relax.
# Requirements:
#  pip install pycryptodome

import argparse, base64, itertools, string, time
from Crypto.Cipher import AES
from multiprocessing import Pool, cpu_count

def charset_from_name(name):
    if name == "lowernum":
        return string.ascii_lowercase + string.digits
    if name == "alnum":
        return string.ascii_letters + string.digits
    if name == "all":
        return string.ascii_letters + string.digits + string.punctuation
    return name  # custom string

def zero_pad(b, block=16):
    return b[:block] if len(b) >= block else b + b'\x00'*(block - len(b))

def decrypt_raw(ct_bytes, key_str):
    try:
        key_bytes = key_str.encode('utf-8')
        key16 = zero_pad(key_bytes, 16)
        cipher = AES.new(key16, AES.MODE_ECB)
        pt = cipher.decrypt(ct_bytes)
        pt = pt.rstrip(b'\x00')  # zero-padding removed on right
        return pt
    except Exception:
        return None

def looks_like_human_text(s: str):
    # conservative heuristic: printable high, contains whitespace, and at least 4 letters
    if not s:
        return False
    printable = sum(1 for ch in s if 32 <= ord(ch) < 127) / max(1, len(s))
    letters = sum(1 for ch in s if ch.isalpha())
    if " " in s and letters >= 4 and printable >= 0.75:
        return True
    # fallback: common english words with decent printable ratio
    low = s.lower()
    if printable >= 0.7 and any(w in low for w in ("the", "is", "this", "today", "flag", "password", "secret", "welcome")):
        return True
    return False

def gen_from_mask(mask_list, positions, charset):
    if not positions:
        yield ''.join(mask_list)
        return
    for prod in itertools.product(charset, repeat=len(positions)):
        tmp = list(mask_list)
        for p,ch in zip(positions, prod):
            tmp[p] = ch
        yield ''.join(tmp)

def gen_fixed_length(length, charset):
    for prod in itertools.product(charset, repeat=length):
        yield ''.join(prod)

def worker_check(chunk, ct_bytes, accept_any_utf8):
    for k in chunk:
        pt = decrypt_raw(ct_bytes, k)
        if pt is None:
            continue
        # try decode as utf-8
        try:
            s = pt.decode('utf-8')
        except Exception:
            continue
        if accept_any_utf8 or looks_like_human_text(s):
            return (k, s)
    return None

def chunked_iterable(it, size):
    it = iter(it)
    while True:
        chunk = list(itertools.islice(it, size))
        if not chunk:
            break
        yield chunk

def main():
    p = argparse.ArgumentParser(description="Bruteforce AES-ECB zero-pad key search (raw key only)")
    p.add_argument("--b64", required=True, help="ciphertext in base64")
    p.add_argument("--mask", help="key mask with unknown marker (default '?'), e.g. ?Y5?V9")
    p.add_argument("--unknown", default='?', help="unknown marker character used in mask (default '?'). If your mask uses ▆ replace it with ? before running.")
    p.add_argument("--length", type=int, help="fixed-length brute (if mask not provided)")
    p.add_argument("--charset", default="alnum", help="charset name: lowernum, alnum, all or provide exact set")
    p.add_argument("--batch", type=int, default=4000, help="keys per worker task")
    p.add_argument("--accept-any-utf8", action="store_true", help="accept any utf-8-decodable plaintext (less strict)")
    p.add_argument("--max-tries", type=int, default=0, help="stop after N tries (0 = no limit)")
    args = p.parse_args()

    ct_bytes = base64.b64decode(args.b64)
    charset = charset_from_name(args.charset)
    num_workers = max(1, cpu_count() - 1)

    # build generator and total
    if args.mask:
        # allow using other unknown marker (e.g. '!' or '▆') by replacing with '?'
        mask_str = args.mask
        unknown = args.unknown
        if unknown != '?':
            mask_str = mask_str.replace(unknown, '?')
        mask_list = list(mask_str)
        positions = [i for i,c in enumerate(mask_list) if c == '?']
        total = len(charset) ** len(positions)
        gen = gen_from_mask(mask_list, positions, charset)
    else:
        if not args.length:
            print("Either --mask or --length must be provided.")
            return
        length = args.length
        total = len(charset) ** length
        gen = gen_fixed_length(length, charset)

    print(f"CHARSET size = {len(charset)}, total combinations = {total:,}, workers = {num_workers}")
    if total > 500_000_000:
        print("Warning: extremely large search space. Consider narrowing charset or mask.")
    start = time.time()

    pool = Pool(processes=num_workers)
    tasks = []
    dispatched = 0
    try:
        for chunk in chunked_iterable(gen, args.batch):
            dispatched += len(chunk)
            tasks.append(pool.apply_async(worker_check, (chunk, ct_bytes, args.accept_any_utf8)))
            # check finished
            if len(tasks) >= num_workers * 3:
                new_tasks = []
                for t in tasks:
                    if t.ready():
                        res = t.get()
                        if res:
                            key_found, plaintext = res
                            elapsed = time.time() - start
                            print("\n" + "="*60)
                            print("FOUND KEY:", key_found)
                            print("PLAINTEXT:", plaintext)
                            print(f"tried ~{dispatched} keys in {int(elapsed)}s")
                            with open("found_result.txt", "w", encoding="utf-8") as f:
                                f.write(f"KEY: {key_found}\nPLAINTEXT: {plaintext}\n")
                            pool.terminate()
                            return
                    else:
                        new_tasks.append(t)
                tasks = new_tasks
            # progress
            if dispatched % max(1, (args.batch * 25)) < args.batch:
                elapsed = time.time() - start
                rate = dispatched / max(1, elapsed)
                eta = (total - dispatched) / rate if rate > 0 else float('inf')
                print(f"Tried ~{dispatched:,} / {total:,} (elapsed {int(elapsed)}s, {int(rate):,} keys/s, ETA {int(eta)}s)")
            if args.max_tries and dispatched >= args.max_tries:
                print("Reached max-tries limit. Stopping dispatch.")
                break

        # collect remaining
        for t in tasks:
            res = t.get()
            if res:
                key_found, plaintext = res
                elapsed = time.time() - start
                print("\n" + "="*60)
                print("FOUND KEY:", key_found)
                print("PLAINTEXT:", plaintext)
                print(f"tried ~{dispatched} keys in {int(elapsed)}s")
                with open("found_result.txt", "w", encoding="utf-8") as f:
                    f.write(f"KEY: {key_found}\nPLAINTEXT: {plaintext}\n")
                pool.terminate()
                return

        elapsed = time.time() - start
        print("Search complete. No likely plaintext found.")
        print(f"Tried {dispatched:,} keys in {int(elapsed)}s.")
    finally:
        pool.close()
        pool.join()

if __name__ == "__main__":
    main()
