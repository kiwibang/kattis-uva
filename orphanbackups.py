# i gave up, not sure what the bug is in my original cpp code :(((
# credits: https://github.com/RussellDash332/kattis/blob/main/src/Orphan%20Backups/orphanbackups.py
import sys
files = {}
backups = []
for l in sys.stdin:
    l = l.rstrip()
    if not l: break
    files[l] = []
for l in sys.stdin:
    l = l.rstrip()
    filename = l
    for _ in range(2): filename = filename[:filename.rfind('_')]
    if filename not in files: backups.append(l)
    else: files[filename].append(l)
allmatch = 1
for i in sorted(backups): 
    print('F', i)
    allmatch = 0
for i in sorted(files):
    if not files[i]: 
        print('I', i)
        allmatch = 0
if allmatch: print('No mismatches.')
