#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

ts = [i*(i+1)/2 for i in range(0, 100)]
words = open("/Users/draftcode/Downloads/words.txt").read().replace("\"", '').split(',')

ans = 0
for word in words:
    s = 0
    for c in word:
        s += ord(c) - ord('A') + 1
    if s in ts:
        ans += 1

print ts
print ans

