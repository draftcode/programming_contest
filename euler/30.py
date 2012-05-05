#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals
import itertools

tab = []
for i in range(0, 10):
    t = i
    for k in range(4):
        t *= i
    tab.append(t)
print tab

k = 9
s = tab[9]
while k < s:
    k *= 10
    k += 9
    s += tab[9]
print k

# for p in range(100000, 10000000):
#     s = 0
#     for c in str(p):
#         s += tab[int(c)]
#     if s == p:
#         print p
# print 'DONE'
