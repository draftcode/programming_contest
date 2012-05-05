#!/usr/bin/env python2.7
# vim: fileencoding=utf-8
from __future__ import unicode_literals

nu = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
nu2 = [None,
       'twenty',
       'thirty',
       'forty',
       'fifty',
       'sixty',
       'seventy',
       'eighty',
       'ninety']

def l(n):
    if n == 1000:
        return "one thousand"
    elif n >= 100:
        k = n / 100
        n = n % 100
        ret = nu[k-1] + " hundred"
        if n != 0:
            ret += " and " + l(n)
        return ret
    elif n >= 21:
        k = n / 10
        n = n % 10
        ret = nu2[k-1]
        if n != 0:
            ret += ' ' + l(n)
        return ret
    elif n == 20:
        return 'twelve'
    elif n == 19:
        return 'nineteen'
    elif n == 18:
        return 'eighteen'
    elif n == 17:
        return 'seventeen'
    elif n == 16:
        return 'sixteen'
    elif n == 15:
        return 'fifteen'
    elif n == 14:
        return 'fourteen'
    elif n == 13:
        return 'thirteen'
    elif n == 12:
        return 'twelve'
    elif n == 11:
        return 'eleven'
    elif n == 10:
        return 'ten'
    else:
        return nu[n-1]

print l(342)
print len(l(342).replace(' ', ''))
ans = 0
for i in range(1, 1001):
    ans += len(l(i).replace(' ', ''))
print ans
