#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

def f(n, div):
    seen = set()
    ret = "0."
    while n != 0:
        while n < div:
            n *= 10
        ret += str(n / div)
        n = n % div
        if n in seen:
            ret = ret[0:-1]
            break
        seen.add(n)
    return ret


print max([(f(1, n), n) for n in range(2, 1000)], key=lambda p: len(p[0]))[1]

