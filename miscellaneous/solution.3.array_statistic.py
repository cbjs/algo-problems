#!/usr/bin/env python
#coding:utf-8
#
#   方法1:
#       从左至右扫描数组, 破坏原数组, 用<=0的数计数-1表示出现了一次，-2出现了两次
#
#   方法2:
#       三遍扫描，1) a[i] = a[i] * n
#                 2) a[a[i] / n - 1] ++
#                 3) a[i] % n 为(i + 1)出现的次数

def solution_one(arr):
    i = 0
    while i < len(arr):
        if arr[i] <= 0:
            i += 1
            continue

        if arr[i] == i + 1:
            arr[i] = -1
            i += 1
        else:
            if arr[arr[i] - 1] <= 0:
                arr[arr[i] - 1] -= 1
                arr[i] = 0
                i += 1
            else:
                tmp = arr[arr[i] - 1]
                arr[arr[i] - 1] = -1
                arr[i] = tmp

    # output
    for i, v in enumerate(arr):
        if v < 0:
            print "%d : %d" % (i + 1, abs(v))

def solution_two(arr):
    n = len(arr)
    # round 1
    for i in range(n):
        arr[i] *= n

    # round 2
    for i in range(n):
        arr[arr[i] / n - 1] += 1

    # round 3
    for i in range(n):
        num = arr[i] % n
        if num > 0:
            print "%d : %d" % (i + 1, num)


if __name__ == '__main__':
    arr = [1, 8, 3, 1, 5, 1, 2, 8, 9, 9]
    print "solution_one:"
    solution_one(arr)
    print "solution_two:"
    arr = [1, 8, 3, 1, 5, 1, 2, 8, 9, 9]
    solution_two(arr)
