#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals
import itertools

def f(u, d, U, D):
    if u*D == d*U and d*U != 0 and u != d:
        print '%d/%d' % (U, D)

for u, l, c in itertools.combinations_with_replacement(range(10), 3):
    f(u*10+c, l*10+c, u, l)
    f(u*10+c, c*10+l, u, l)
    f(c*10+l, l*10+c, u, l)
    f(c*10+l, c*10+l, u, l)

