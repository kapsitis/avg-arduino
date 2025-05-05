import os
import sys
import re

def rename_files(directory):
    pattern = re.compile(r'^(\w+)-(\d+)\.mp3$', re.IGNORECASE)
    for fname in os.listdir(directory):
        match = pattern.match(fname)
        if match:
            new_fname = f"00{match.group(2)}.mp3"
            src = os.path.join(directory, fname)
            dst = os.path.join(directory, new_fname)
            if os.path.exists(dst):
                print(f"Skipping {fname}: destination {new_fname} already exists!")
                continue
            print(f"Renaming {fname} -> {new_fname}")
            os.rename(src, dst)

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python rename_mp3s.py <directory>")
        sys.exit(1)
    rename_files(sys.argv[1])