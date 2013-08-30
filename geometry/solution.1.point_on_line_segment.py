#!/usr/bin/env python
#coding:utf-8
#
#   判断点p是否在线段ab上
#       1. 向量ap 和向量bp的叉积应该等于0, 则ap和bp共线，即p在ab所在直线上
#       2. p的x,y坐标值取值范围在[a.x, b.x]和[a.y b.y]中,假设a.x > b.x and a.y > b.y

def cross_product(a, b):
    return a[0] * b[1] - a[1] * b[0]

def solution(a, b, p):
    return cross_product((a[0] - p[0], a[1] - p[1]), (b[0] - p[0], b[1] - p[1])) == 0 and (p[0] - a[0]) * (p[0] - b[0]) <= 0 and (p[1] - a[1]) * (p[1] - b[1]) <=0

if __name__ == '__main__':
    a = (1, 1)
    b = (2, 2)
    c = (1.5, 1.5)
    print "c in line segment ab: ", solution(a, b, c)
