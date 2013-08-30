#!/usr/bin/env python
#coding:utf-8
#   KMP string matching algorithm

def kmp(P, T):
    # calc longest proper prefix table
    pi = [-1] * len(P)
    k = -1
    for i in range(1, len(P)):
        while k >= 0 and P[i] != P[k + 1]:
            k = pi[k]
        if P[i] == P[k + 1]:
            k = k + 1
        pi[i] = k

    print pi

    # string matching
    l = -1   # index of Pattern already matched to
    for i in range(len(T)):
        while l >=0 and T[i] != P[l + 1]:
            l = pi[l]
        if T[i] == P[l + 1]:
            l += 1
        if l == len(P) - 1:
            print "found at index:%d" % (i - l)
            l = pi[l]

if __name__ == '__main__':
    P = 'ababc'
    T = 'cdabaeababcdababcdef'
    kmp(P, T)
