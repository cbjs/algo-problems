#!/usr/bin/env python
#coding:utf-8

def binary_search(arr, inds, ele, start, end):
    """
        在arr[inds]中找到小于ele的最大元素，返回下标
        arr[inds] = [1, 2, 3, 5, 6]
        ele = 4, return 2
        ele = 1, return -1
    """
    if start == end:
        return -1

    if end - start == 1:
        if arr[inds[start]] < ele:
            return start
        else:
            return -1

    mid = (start + end) / 2
    if arr[inds[mid]] >= ele:
        return binary_search(arr, inds, ele, start, mid)
    else:
        return binary_search(arr, inds, ele, mid, end)

def longest_increasing_subsequence(arr):
    inds = [0] * len(arr)
    max_len = 1
    for i in range(1, len(arr)):
        index = binary_search(arr, inds, arr[i], 0, max_len)
        if index < max_len - 1:
            if arr[inds[index + 1]] > arr[i]:
                inds[index + 1] = i
        else: # index == max_len - 1
            max_len += 1
            inds[index + 1] = i

    print "max length:%d" % max_len

if __name__ == '__main__':
    arr = [12, 1, 2, 3, 7, -14, -12, -10, 4, 5]
    longest_increasing_subsequence(arr)
