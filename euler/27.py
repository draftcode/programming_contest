#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals
import pyprimes

ans_n = 0
ans = 0
for a in range(-999, 1000):
    for b in range(-999, 1000):
        n = 0
        while True:
            if not pyprimes.isprime(n*n + a*n + b):
                break
            n += 1
        if n > ans_n:
            ans_n = n
            ans = a*b
print ans
print ans_n



