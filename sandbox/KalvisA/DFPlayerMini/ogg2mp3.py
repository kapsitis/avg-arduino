import os
import sys
from pydub import AudioSegment
import re

def convert_ogg_to_mp3(directory):

    pattern = re.compile(r'^(.*) - (\d+) - (.*)\.ogg$', re.IGNORECASE)
    for filename in os.listdir(directory):
        # if filename.lower().endswith('.ogg'):
        match = pattern.match(filename)
        if match:
            # ogg_path = os.path.join(directory, filename)
            # mp3_filename = os.path.splitext(filename)[0] + ".mp3"
            new_fname = f"00{match.group(2)}.mp3"
            src = os.path.join(directory, filename)
            dst = os.path.join(directory, new_fname)


            # Skip if the .mp3 already exists
            if os.path.exists(dst):
                print(f"Skipping {filename}, {dst} already exists.")
                continue

            print(f"Converting {filename} -> {new_fname}")

            audio = AudioSegment.from_ogg(src)
            audio.export(dst, format="mp3")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python ogg2mp3.py <directory>")
        sys.exit(1)
    convert_ogg_to_mp3(sys.argv[1])