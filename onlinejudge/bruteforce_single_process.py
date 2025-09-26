# bruteforce_key_search.py
# Supports custom unknown marker via --unknown and backslash-escaping for literal chars in mask.
# Usage:
#   python bruteforce_key_search.py --b64 "<BASE64>" --mask '▆-?5Q▆E▆qeDe▆%Bs' --unknown '▆' --charset all
#   python bruteforce_key_search.py --b64 "<BASE64>" --mask 'a\?b!c' --unknown '!'  (here '?' is literal because escaped)
#
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
    return name

def zero_pad(b, block=16):
    return b[:block] if len(b) >= block else b + b'\x00'*(block - len(b))

def decrypt_raw(ct_bytes, key_str):
    try:
        key_bytes = key_str.encode('utf-8')
        key16 = zero_pad(key_bytes, 16)
        cipher = AES.new(key16, AES.MODE_ECB)
        pt = cipher.decrypt(ct_bytes)
        pt = pt.rstrip(b'\x00')
        return pt
    except Exception:
        return None

def looks_like_human_text(s: str):
    if not s:
        return False
    printable = sum(1 for ch in s if 32 <= ord(ch) < 127) / max(1, len(s))
    letters = sum(1 for ch in s if ch.isalpha())
    if " " in s and letters >= 4 and printable >= 0.75:
        return True
    low = s.lower()
    if printable >= 0.7 and any(w in low for w in ("the","is","this","today","flag","password","secret","welcome")):
        return True
    return False

def parse_mask(mask_str: str, unknown_marker: str):
    """
    Parse mask string allowing backslash-escaping.
    Returns list where literal chars are the char, and unknown positions are None.
    Example: parse_mask(r'a\?b▆c', unknown='▆') => ['a','?','b', None, 'c']
    """
    res = []
    i = 0
    L = len(mask_str)
    while i < L:
        ch = mask_str[i]
        if ch == '\\' and i+1 < L:
            # escape next char -> literal
            res.append(mask_str[i+1])
            i += 2
            continue
        if ch == unknown_marker:
            res.append(None)
            i += 1
            continue
        res.append(ch)
        i += 1
    return res

def gen_from_mask(mask_list, positions, charset):
    if not positions:
        # join mask_list (should have no None)
        yield ''.join(ch for ch in mask_list)
        return
    for prod in itertools.product(charset, repeat=len(positions)):
        tmp = list(mask_list)
        for p,ch in zip(positions, prod):
            tmp[p] = ch
        yield ''.join(tmp)

def gen_fixed_length(length, charset):
    for prod in itertools.product(charset, repeat=length):
        yield ''.join(prod)

def chunked_iterable(it, size):
    it = iter(it)
    while True:
        chunk = list(itertools.islice(it, size))
        if not chunk:
            break
        yield chunk

def worker_check(chunk, ct_bytes, accept_any_utf8):
    for k in chunk:
        pt = decrypt_raw(ct_bytes, k)
        if pt is None:
            continue
        try:
            s = pt.decode('utf-8')
        except:
            continue
        if accept_any_utf8 or looks_like_human_text(s):
            return (k, s)
    return None

def main():
    p = argparse.ArgumentParser(description="Bruteforce AES-ECB zero-pad key search (supports custom unknown marker and escaping)")
    p.add_argument("--b64", required=True)
    p.add_argument("--mask", help="mask string with unknown_marker positions (supports backslash escaping for literal chars)")
    p.add_argument("--unknown", default='?', help="unknown marker character used in mask (default '?')")
    p.add_argument("--length", type=int, help="fixed-length brute (if mask not provided)")
    p.add_argument("--charset", default="alnum")
    p.add_argument("--batch", type=int, default=4000)
    p.add_argument("--accept-any-utf8", action="store_true")
    p.add_argument("--max-tries", type=int, default=0)
    args = p.parse_args()

    ct_bytes = base64.b64decode(args.b64)
    charset = charset_from_name(args.charset)
    num_workers = max(1, cpu_count() - 1)

    if args.mask:
        mask_list = parse_mask(args.mask, args.unknown)
        positions = [i for i,c in enumerate(mask_list) if c is None]
        total = len(charset) ** len(positions)
        gen = gen_from_mask(mask_list, positions, charset)
    else:
        if not args.length:
            print("Either --mask or --length must be provided.")
            return
        total = len(charset) ** args.length
        gen = gen_fixed_length(args.length, charset)

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
            if dispatched % max(1, (args.batch * 25)) < args.batch:
                elapsed = time.time() - start
                rate = dispatched / max(1, elapsed)
                eta = (total - dispatched) / rate if rate > 0 else float('inf')
                print(f"Tried ~{dispatched:,} / {total:,} (elapsed {int(elapsed)}s, {int(rate):,} keys/s, ETA {int(eta)}s)")
            if args.max_tries and dispatched >= args.max_tries:
                print("Reached max-tries limit. Stopping dispatch.")
                break

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

if __name__ == '__main__':
    main()
