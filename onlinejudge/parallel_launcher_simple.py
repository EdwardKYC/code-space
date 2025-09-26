# parallel_launcher_simple.py
import argparse, string, subprocess, sys, os

def charset_all():
    return string.ascii_letters + string.digits + string.punctuation

def chunk_list(lst, n):
    k, m = divmod(len(lst), n)
    chunks = []
    i=0
    for j in range(n):
        sz = k + (1 if j < m else 0)
        chunks.append(lst[i:i+sz])
        i += sz
    return chunks

if __name__ == "__main__":
    p = argparse.ArgumentParser()
    p.add_argument("--b64", required=True)
    p.add_argument("--mask", required=True)
    p.add_argument("--workers", type=int, default=None, help="number of parallel processes (default env NUMBER_OF_PROCESSORS)")
    p.add_argument("--batch", type=int, default=200000)
    p.add_argument("--charset", default="all")
    args = p.parse_args()

    if args.workers is None:
        try:
            args.workers = int(os.environ.get("NUMBER_OF_PROCESSORS", "1"))
        except:
            args.workers = 1

    if args.charset == "all":
        cs = list(charset_all())
    else:
        cs = list(args.charset)

    parts = chunk_list(cs, args.workers)
    print(f"Launching {len(parts)} processes")
    for i, part in enumerate(parts):
        prefixes = "".join(part)
        cmd = [
            sys.executable,
            r"c:\coding\code\code-space\onlinejudge\bruteforce_single_process.py",
            "--b64", args.b64,
            "--mask", args.mask,
            "--charset", args.charset,
            "--batch", str(args.batch),
            "--prefixes", prefixes
        ]
        print("Starting:", " ".join(cmd))
        subprocess.Popen(cmd)
