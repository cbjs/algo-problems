#!/usr/bin/env python
#coding:utf-8

def solution(arr):
    """
        n = len(arr)
        1. 扫描数组，将整数1 <= k <= n, 的整数放到arr[k - 1]的位置上
        2. 扫描数组. 第一个arr[i] != i + 1的i, i + 1就是要找的数
    """
    n = len(arr)
    # 1st scan
    i = 0
    while i < n:
        k = arr[i]
        if k >= 1 and k <= n:
            if arr[k - 1] != k:
                tmp = arr[k - 1]
                arr[k - 1] = k
                arr[i] = tmp
                continue
        i += 1

    # 2nd scan
    for i in range(n):
        if arr[i] != i + 1:
            return i + 1

    return len(arr) + 1

if __name__ == '__main__':
    arr = [1, 2, 0]
    print "solution of %r: %d" % (arr, solution(arr))

    arr = [7, 1, 3, 9, 9, -1, -2]
    print "solution of %r: %d" % (arr, solution(arr))

    arr = [1, 2, 3, 4]
    print "solution of %r: %d" % (arr, solution(arr))

    arr = [3, 3, 3, 3]
    print "solution of %r: %d" % (arr, solution(arr))
