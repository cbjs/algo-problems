#!/usr/bin/env python
#coding:utf-8
#
# Given n types of coin denominations: v[n],
#   let M[I] be minimum number of coins needed to make change for an 
#   amount of money I, then
# M[I] = min{M[I - v[k]]} + 1, where v[k] <= I, k = 1..n
# 
# To track how many coins of each denomination used, 
#   let T[I] = k

import sys

def solution(v, C):
    if not 1 in v:
        v.append(1)
    v.sort()

    # init
    M = [0] * (C + 1)
    T = [0] * (C + 1)

    # iterate
    for I in range(1, len(M)):
        T[I] = 0
        M[I] = M[I - 1] + 1
        for k, d in enumerate(v):
            if d <= I and (M[I - d] + 1) < M[I]:
                T[I] = k
                M[I] = M[I - d] + 1

    # output
    print "minimum coins needed for %d: %d" % (C, M[C])
    coins_set = {}
    I = C
    while I != 0: 
        k = T[I]
        d = v[k]
        if not d in coins_set:
            coins_set[d] = 1
        else:
            coins_set[d] += 1
        I -= d
    for k,v in coins_set.items():
        print "denomination %d: %d" % (k, v)

if __name__ == '__main__':
    v = [1, 5, 7]
    C = 100
    solution(v, C)
