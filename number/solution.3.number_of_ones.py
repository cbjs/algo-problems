#!/usr/bin/env python
#coding:utf-8

def solution_one(n):
    num = 0
    while n != 0:
        if n & 0x01 != 0:
            num += 1
        n = n >> 1
    return num

def solution_two(n):
    num = 0
    while n != 0:
        if n % 2 != 0:
            num += 1
        n /= 2
    return num

def solution_three(n):
    num = 0
    while n != 0:
        num += 1
        n = n & (n - 1)
    return num


if __name__ == '__main__':
    print "solution_one:%d = %d" % (139, solution_one(139))
    print "solution_two:%d = %d" % (139, solution_two(139))
    print "solution_three:%d = %d" % (139, solution_three(139))
