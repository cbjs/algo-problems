#!/usr/bin/env python
#coding:utf-8
#
#

class point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return "(%r, %r)" % (self.x, self.y)

class line_seg(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __repr__(self):
        return "line_seg:%r->%r" % (self.start, self.end)

def cross_product(v1, v2):
    """cross product of two vector"""
    return (v1.x * v2.y) - (v1.y * v2.x)

def cross_product_x(a, b, p):
    """cross product of vector ap and bp"""
    ap = point(a.x - p.x, a.y - p.y)
    bp = point(b.x - p.x, b.y - p.y)
    return cross_product(ap, bp)

def solution(line1, line2):
    return max(line1.start.x, line1.end.x) >= min(line2.start.x, line2.end.x) and\
            max(line1.start.y, line1.end.y) >= min(line2.start.y, line2.end.y) and\
            max(line2.start.x, line2.end.x) >= min(line1.start.x, line1.end.x) and\
            max(line2.start.y, line2.end.y) >= min(line1.start.y, line1.end.y) and\
            cross_product_x(line1.end, line2.start, line1.start) * cross_product_x(line2.end, line1.end, line1.start) >= 0 and\
            cross_product_x(line2.end, line1.start, line2.start) * cross_product_x(line1.end, line2.end, line2.start) >=0

if __name__ == '__main__':
    line_seg_1 = line_seg(point(0, 0), point(2, 2))
    line_seg_2 = line_seg(point(0, 1), point(2, 3))
    print "%r intersect with %r: %r" % (line_seg_1, line_seg_2, solution(line_seg_1, line_seg_2))

    line_seg_1 = line_seg(point(0, 0), point(2, 2))
    line_seg_2 = line_seg(point(0, 1), point(1, 0))
    print "%r intersect with %r: %r" % (line_seg_1, line_seg_2, solution(line_seg_1, line_seg_2))
