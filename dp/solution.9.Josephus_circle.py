#!/usr/bin/env python
#coding:utf-8
#
# n个人编号0...n - 1, 先不考虑m, 从0开始计数，枪毙第k个人后
#   0, 1, ..., k - 2, k, ..., n - 1
#
# 从k开始重新对应0...n - 2编号
#   序列1: k, k + 1, k + 2, ...,     n - 1,     0, ..., k - 3, k - 2
#   序列2: 0,     1,     2, ..., n - k - 1, n - k, ..., n - 3, n - 2
# 
# 继续计数，枪毙第k个人
# 变成一个子问题, n - 1个人编号0...n - 2, 枪毙第k个人
#
# 设J(n, k) 表示n个人编号0...n - 1, 每次枪毙第k个人, 最后活下来的人的编号。
#
# J(n - 1, k) 是上面序列2中的一个，对应于序列1中编号应该是(J(n - 1, k) + k) % n
#   因此有, 
#       J(n, k) = (J(n - 1, k) + k) % n, J(1, k) = 0
#
# 最后考虑m, 第一次枪毙第m个人而不是第k个人
# 对应编号应该是J(n, k) = (J(n - 1, k) + m) % n


import sys
import random

def solution(n, m, k):
    s = 0

    # from 2 to n - 1
    for i in range(2, n):
        s = (s + k) % i

    # 返回编号[1, n], 因此加1
    return (s + m) % n + 1

if __name__ == '__main__':
    for i in range(100):
        n = random.randint(10, 10000)
        m = random.randint(1, n)
        k = random.randint(1, n)
        print 'Josephus Problem(n:%d, m:%d, k:%d): %d' % (n, m, k, solution(n, m, k))
