#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

sum = 0
for i in range(1, 1000001):
    ds = str(i)
    bs = bin(i)[2:]
    if ds == ds[::-1] and bs == bs[::-1]:
        sum += i
print sum
