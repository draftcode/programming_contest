#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

r = []
for i in range(0, 10):
    t = 1
    for k in range(1, i+1):
        t *= k
    r.append(t)
print r

k = 9
s = r[9]
while k < s:
    k *= 10
    k += 9
    s += r[9]
print k

