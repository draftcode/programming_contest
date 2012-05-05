#!/usr/bin/env python2.7
# vim: fileencoding=utf-8

trans = {' ': ' ',
         'a': 'y',
         'b': 'h',
         'c': 'e',
         'd': 's',
         'e': 'o',
         'f': 'c',
         'g': 'v',
         'h': 'x',
         'i': 'd',
         'j': 'u',
         'k': 'i',
         'l': 'g',
         'm': 'l',
         'n': 'b',
         'o': 'k',
         'p': 'r',
         'q': 'z',
         'r': 't',
         's': 'n',
         't': 'w',
         'u': 'j',
         'v': 'p',
         'w': 'f',
         'x': 'm',
         'y': 'a',
         'z': 'q'}

i = 0
for l in open('A-small-attempt0.in'):
    if i == 0:
        i += 1
    else:
        l = ''.join([trans[c] for c in l.strip()])
        print "Case #%d: %s" % (i, l)
        i += 1

