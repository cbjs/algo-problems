#!/usr/bin/env python
#coding:utf-8

def lcprefix(S):
    """
        Z Algorithm
        维护一个区间[L, R], S[L, R]为有最大的R值前缀子串
        从左向右扫描字符串, 假设前i个已经计算完成，准备计算Z[i]
        如果i <= R, 
            设k = i - L, 则S[k:]和S[i:]具有至少长度为R - i + 1的前缀
            如果Z[k] < R - i + 1, 设置Z[i] = Z[k], 继续循环
            否则, 在匹配S[0:]和S[i:]计算Z[i]时, 可以跳过R - i + 1个长度
                计算完后，重新设置L, R
        如果i > R, 比较S[0:]和S[i:]计算Z[i], 设置L = i, R = i + Z[i] - 1
        
    """
    # init
    Z = [len(S)] * len(S)

    L = R = 0
    for i in range(1, len(S)):
        if i > R:
            L = R = i
            while R < len(S) and S[R - L] == S[R]:
                R += 1
            Z[i] = R - L
            R -= 1
        else:
            k = i - L
            if Z[k] < R - i + 1:
                Z[i] = Z[k]
            else:
                L = i
                while R < len(S) and S[R - L] == S[R]:
                    R += 1
                Z[i] = R - L
                R -= 1

    return Z

if __name__ == '__main__':
    S = 'aabcdeaaabcdaabg'
    Z = lcprefix(S)
    print '[ %s]' % ', '.join(S)
    print Z
