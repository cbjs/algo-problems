#!/usr/bin/env python
#coding:utf-8
#
# 辗转相除法
#   gcd(a, b) = gcd(b, a % b)
# 求gcd(a, b) = a * x + b * y
#
#   当b = 0, gcd(a, b) = a * 1 + b * 0 = a
#
#   设a = k * b + r
#
#   gcd(a, b) = a * x + b * y
#             = (k * b + r) * x + b * y
#             = b * (k * x + y) + r * x
#             = b * x1 + r * y1
#             = gcd(b, r)
#
#    x = y1, y = x1 - k * x

def solution(a, b):
    if a == 0 or b == 0:
        return max(a, b)

    while True:
        r = a % b
        if r == 0:
            return b
        a = b
        b = r

def solution_ext(a, b):
    if a == 0:
        return (b, 0, 1)
    if b == 0:
        return (a, 1, 0)
    
    gcd, x1, y1 = solution_ext(b, a % b)
    x = y1
    y = x1 - (a / b) * y1
    return (gcd, x, y)

def solution_two(a, b):
    if a == 0 or b == 0:
        return max(a, b)

    if not (a & 0x01) and not (b & 0x01):
        return solution_two(a >> 1, b >> 1) << 1
    elif not (a & 0x01):
        return solution_two(a >> 1, b)
    elif not (b & 0x01):
        return solution_two(a, b >> 1)
    else:
        return solution_two(abs(a - b), min(a, b))

if __name__ == '__main__':
    a = 1920
    b = 1680
    print "gcd(%d, %d) = %d" % (a, b, solution(a, b))
    print "gcd(%d, %d) = %d" % (a, b, solution_two(a, b))

    gcd, x, y = solution_ext(a, b)
    print "gcd(%d, %d) = %d * %d + %d * %d = %d" % (a, b, a, x, b, y, gcd)

    t = a
    a = b
    b = t
    gcd, x, y = solution_ext(a, b)
    print "gcd(%d, %d) = %d * %d + %d * %d = %d" % (a, b, a, x, b, y, gcd)
