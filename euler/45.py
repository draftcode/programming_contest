#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

def trigen(n):
    while True:
        yield n*(n+1)/2
        n += 1

def pentagen(n):
    while True:
        yield n*(3*n-1)/2
        n += 1

def hexgen(n):
    while True:
        yield n*(2*n-1)
        n += 1

def f(A, B, C):
    a = A.next()
    b = B.next()
    c = C.next()
    while True:
        if a < b:
            a = A.next()
        elif b < c:
            b = B.next()
        elif c < a:
            c = C.next()
        else:
            break
    print a

f(trigen(286), pentagen(165), hexgen(143))
