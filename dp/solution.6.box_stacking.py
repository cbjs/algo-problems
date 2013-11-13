#!/usr/bin/env python
#coding:utf-8
#
#   观察三点:
#       1. 如果一个盒子A能放在另一个盒子B上, A盒子结合面的面积一定严格小于B盒子结合面的面积
#       2. 同一类盒子(相同的盒子)不能堆叠在一起, 因为要求上面盒子严格小于下面的盒子
#       3. 每个盒子有3个面积: height * width, height * depth, width * depth
#
#   问题转换:
#       n个类型的盒子，3n个面积，从大到小排序，求最长递减子序列
#

def solution(boxes):

    # store 3 areas and height of each box
    area_height = []

    # put (area, height, box_index) tuple in area_height
    for index, box in enumerate(boxes):
        for i in range(3):
            j = (i + 1) % 3
            k = (i + 2) % 3
            area_height.append({
                'area': box[i] * box[j],
                'min_border': min(box[i], box[j]),
                'max_border': max(box[i], box[j]),
                'height': box[k],
                'box_index': index
            })

    # sort by area_height by area in decending order
    # print area_height
    area_height.sort(key = lambda area_height_tuple: area_height_tuple['area'], reverse = True)
    # print area_height

    # max height with box[i] on the top
    max_height = [0] * len(area_height)
    max_height[0] = area_height[0]['height']

    # box index below current box for backtrace
    box_below = [-1] * len(area_height)

    # iterate
    max_height_index = 0
    for i in range(1, len(area_height)):
        for j in range(0, i):
            if area_height[j]['min_border'] > area_height[i]['min_border'] and area_height[j]['max_border'] > area_height[i]['max_border']:
                if max_height[j] > max_height[i]:
                    max_height[i] = max_height[j]
                    box_below[i] = j
        max_height[i] += area_height[i]['height']
        
        if max_height[i] > max_height[max_height_index]:
            max_height_index = i

    # output
    # print "max_height:%r" % max_height
    # print "box_below:%r" % box_below
    print "max height: %d" % max_height[max_height_index]
    while max_height_index != -1:
        print area_height[max_height_index]
        max_height_index = box_below[max_height_index]

if __name__ == '__main__':
    boxes = [
        (1, 2, 3),
        (2, 4, 5),
        (1, 2, 4),
        (2, 3, 9), 
        (3, 4, 10)
    ]
    solution(boxes)
