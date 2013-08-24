#!/usr/bin/env python
#coding:utf-8

def solution_internal(arr, i, j, value):
    print i, j
    if i == j:
        return -1

    mid = (i + j) / 2

    if arr[mid] == value:
        return mid
    elif arr[mid] < value:
        return solution_internal(arr, mid + 1, j, value)
    else:
        return solution_internal(arr, i, mid, value)


def solution(arr, value):
    return solution_internal(arr, 0, len(arr), value)


def solution_leftmost_internal(arr, i, j, value):
    print i, j
    if i == j:
        if arr[i] == value:
            return i
        else:
            return -1

    mid = (i + j) / 2

    if arr[mid] < value:
        return solution_leftmost_internal(arr, mid + 1, j, value)
    else:
        return solution_leftmost_internal(arr, i, mid, value)

def solution_leftmost(arr, value):
    return solution_leftmost_internal(arr, 0, len(arr) - 1, value)


if __name__ == '__main__':
    arr = [-9, -4, -1, 0, 7, 9, 100, 123, 531, 1200, 78999]
    print "find at %d" % solution(arr, 1200)

    arr = [-9, -4, -1, 0, 7, 8, 99, 100, 100, 100, 531, 1200, 78999]
    print "find at %d" % solution_leftmost(arr, 100)
