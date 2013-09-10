#!/usr/bin/env python
#coding:utf-8

def print_result(flags):
    for i in range(len(flags)):
        if flags[i]:
            print i + 1,
    print ''

def solution(n, m, flags = None):
    """
        分析:
            假设n, m总共有F(n, m)种组合方式
            若n > m, 1..n中m + 1, .., n这n - m个数，不可能在组合中
            若n <= m, 则F(n, m) = F(n - 1, m - n) + F(n - 1, m)
    """
    if not flags:
        flags = [False] * n

    if n <= 0 or m <= 0:
        return

    if n > m:
        n = m

    if n == m:
        flags[n - 1] = True
        print_result(flags)
        flags[n - 1] = False

    flags[n - 1] = True
    solution(n - 1, m - n, flags)
    flags[n - 1] = False

    solution(n - 1, m, flags)

if __name__ == '__main__':
    n = 10
    m = 15
    solution(n, m)
