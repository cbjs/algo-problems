#!/usr/bin/env python
#coding:utf-8
#
#   输入，顺时针或逆时针多边形顶点坐标v1, v2, ..., vn
#
#   方法1:
#       以任意顶点为起点，将多边形划分成三角形，分别求三角形"面积"，再加起来。
#           多边形划分成三角形: <v1, v2, v3>, <v1, v3, v4>, ..., <v1, v[n-1], vn>
#       以求三角形<v1, v2, v3>面积为例，
#           area<v1, v2, v3> = cross_product(v1:v2, v1:v3) / 2
#
#   方法2:
#       对每个线段求积分, 再加起来。
#   求线段v1(x1, y1) -> v2(x2, y2) 的积分:(可推导出来)
#       integral(v1, v2) = (y1 + y2) * (x2 - x1) / 2
#

def cross_product(a, b, p):
    """cross product of vector ap and bp"""
    ap = (a[0] - p[0], a[1] - p[1])
    bp = (b[0] - p[0], b[1] - p[1])
    return ap[0] * bp[1] - ap[1] * bp[0]

def solution_one(polygon_points):
    area = 0
    if len(polygon_points) < 3:
        return area

    v1 = polygon_points[0]
    for i in range(1, len(polygon_points) - 1):
        v2 = polygon_points[i]
        v3 = polygon_points[i + 1]
        area += cross_product(v2, v3, v1)

    area /= 2.0
    return abs(area)

def solution_two(polygon_points):

    area = 0
    n = len(polygon_points)
    if n < 3:
        return area

    polygon_points.append(polygon_points[0])
    for i in range(n):
        v1 = polygon_points[i]
        v2 = polygon_points[i + 1]
        area += (v2[1] + v1[1]) * (v2[0] - v1[0])

    area /= 2.0
    return abs(area)

if __name__ == '__main__':
    polygon_points = [(0, 0), (1, -0.523), (-1, 1.25), (10.13, 812.12)]
    print "%r area: %r" % (polygon_points, solution_one(polygon_points))
    print "%r area: %r" % (polygon_points, solution_two(polygon_points))
