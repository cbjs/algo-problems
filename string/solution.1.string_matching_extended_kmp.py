#!/usr/bin/env python
#coding:utf-8

def extended_kmp(T, P):
    """
        Extended KMP算法

        计算后缀字符串T[i,]与模式串P的最长公共前缀长度LCP[i]
            若LCP[i] == len(P), 则在i找到P

        算法，第一步先计算模式后缀字符串P[i, ]与P自己的最长公共前缀长度PLCP[i]
            设R[i] = i + PLCP[i]，记录前i-1次计算中得到的最大值R, 设L = i, 
            区间[L, R], R为当前匹配到的字符串最右位置, P[L, R]为最右前缀
            当i < R时, 
    """
    PLCP = [len(P)] * len(P)

    L = R = 0
    for i in range(1, len(P)):
        if i > R:
            L = R = i
            while R < len(P) and P[R - L] == P[R]:
                R += 1
            PLCP[i] = R - L
            R -= 1
        else:
            k = i - L
            if PLCP[k] < R - i + 1:
                PLCP[i] = PLCP[k]
            else:
                L = i
                while R < len(P) and P[R - L] == P[R]:
                    R += 1
                PLCP[i] = R - L
                R -= 1

    L = R = -1
    LCP = [0] * len(T)
    for i in range(len(T)):
        if i > R:
            L = R = i
            while R < len(T) and R - L < len(P) and P[R - L] == T[R]:
                R += 1
            LCP[i] = R - L
            R -= 1
            # check found or not
            if LCP[i] == len(P):
                print "find at index: %d" % i
        else:
            k = i - L
            if PLCP[k] < R - i + 1:
                LCP[i] = PLCP[k]
            else:
                L = i
                while R < len(T) and R - L < len(P) and P[R - L] == T[R]:
                    R += 1
                LCP[i] = R - L
                R -= 1
                # check found or not
                if LCP[i] == len(P):
                    print "find at index: %d" % i

if __name__ == '__main__':
    P = 'abcbabab'
    T = 'cdababcbababdababcbababef'
    extended_kmp(T, P)
