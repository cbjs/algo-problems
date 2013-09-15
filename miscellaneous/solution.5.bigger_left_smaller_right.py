#!/usr/bin/env python
#coding:utf-8

def solution(arr):
    """
        使用一个辅助数组, aux_arr[i]记录从i到n-1所有数中最小的
        从左至右扫描数组，记录从0到i最大的数
    """
    aux_arr = [0] * len(arr)
    min_to_right = arr[-1]
    for i in reversed(range(len(arr))):
        if arr[i] < min_to_right:
            min_to_right = arr[i]
        aux_arr[i] = min_to_right

    max_from_left = arr[0]
    for i in range(len(arr)):
        if arr[i] > max_from_left:
            max_from_left = arr[i]

        if max_from_left <= arr[i] and arr[i] <= aux_arr[i]:
            print "at [%d]: %d" % (i, arr[i])

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5]
    print arr
    solution(arr)

    arr = [1, 7, 3, 8, 15, 9, 10]
    print arr
    solution(arr)
