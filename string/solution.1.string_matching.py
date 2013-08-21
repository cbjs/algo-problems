#!/usr/bin/env python
#coding:utf-8

def kmp(P, T):
    # calc longest proper prefix table
    pi = [0] * len(P)

    # string matching
    q = 0
    i = 0
    while i < len(T):
        if P[q] == T[i]:
            if q == len(P) - 1:
                print "find at index: %d" % (i - q)
                q = pi[q]
            q += 1
            i += 1
        else:
            if q > 0:
                q = pi[q - 1] + 1
            else:
                i += 1
