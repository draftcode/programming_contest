#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

finds = [1, 10, 100, 1000, 10000, 100000, 1000000]
finds_i = 0
so_far = 0
ans = 1
n = 1
while True:
    s = str(n)
    so_far += len(s)
    if so_far >= finds[finds_i]:
        ans *= int(s[len(s)-(so_far-finds[finds_i])-1])
        print int(s[len(s)-(so_far-finds[finds_i])-1])
        finds_i += 1
        if finds_i == 7:
            break
    n += 1
print ans

