#!/usr/bin/env python
#coding:utf-8
#
#   要求每次操作只能与0交换位置
#   仍然可以实现交换任意两个位置的数字
#   eg. [0, ..., 1, ..., 2, ... ] => [0, ..., 2, ..., 1, ... ] 交换1和2的位置
#       先交换0, 1的位置 [1, ..., 0, ..., 2, ... ]
#       再交换0, 2的位置 [1, ..., 2, ..., 0, ... ]
#       最后交换0, 1, 0回到原位，1和2实现交换[0, ..., 2, ..., 1, ... ]
#   实现exchnage(arr, i, j) 做为原子操作
#
#   依次扫描序列1，若与序列2对应位置值不同，交换序列1中两个值的位置即可
#

def exchnage(arr, i, j):
    """
        交换arr中下标为i, j的两个数字
        若其中一个数字为0直接交换
        否则，以0为中介实现交换
    """
    pos0 = arr.index(0)

    if i == pos0 or j == pos0:
        exchnage_internal(arr, i, j)
    else:
        # 交换arr[i] 和 0
        exchnage_internal(arr, i, pos0)
        # arr[i] = 0, 交换arr[i] 和 arr[j]
        exchnage_internal(arr, i, j)
        # arr[j] = 0, 交换arr[j] 和 arr[pos0]
        exchnage_internal(arr, j, pos0)

def exchnage_internal(arr, i, j):
    """交换arr中下标为i, j的两个数字"""
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp
    print " -> %r" % arr,

def solution(arr1, arr2):
    if len(arr1) != len(arr2):
        print "wrong input."

    print "\n"
    print arr1,

    # 遍历数组，如果两个序列不相同，实施交换
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            try:
                j = arr1.index(arr2[i])
                exchnage(arr1, i, j)
            except Exception, e:
                print "wrong input"
                return

if __name__ == '__main__':
    a = [0, 1, 2, 3, 4]
    b = [1, 4, 3, 2, 0]
    solution(a, b)

    a = [0, 1, 2]
    b = [0, 2, 1]
    solution(a, b)
