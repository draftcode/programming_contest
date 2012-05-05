#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals
import pyprimes

primes = set()
for i in pyprimes.primes_below(1000000):
    primes.add(i)

count = 0
for i in primes:
    s = str(i)
    b = True
    for _ in range(len(s)):
        if int(s) not in primes:
            b = False
            break
        s = s[1:] + s[0]
    if b:
        count += 1
print count
