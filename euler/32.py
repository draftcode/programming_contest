#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

ans_set = set()
for a in range(1, 10000):
    for b in range(a, 100000):
        c = a * b
        s = ''.join(sorted(str(a) + str(b) + str(c)))
        if len(s) >= 10:
            break
        if s == '123456789':
            ans_set.add(c)

print ans_set
print sum(ans_set)

