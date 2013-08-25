#!/usr/bin/python
#coding:utf-8
#
# Given a sequence of real numbers, A[n]
# let M[i] be the maximum sum of contiguous subsequence end with 
#   at index i, then
#
#   M[i] = M[i - 1] + A[i], if M[i - 1] > 0
#   M[i] = A[i], if M[i - 1] <= 0
#
# To track maximum subsequence, let T[i] be the start index of 
#   contiguous subsequence with maximum sum, then
#  
#   T[i] = T[i - 1], if M[i - 1] > 0
#   T[i] = i, if M[i - 1] <= 0

import sys

def solution(A):
    if len(A) == 0:
        return

    # init
    M = A[:]
    T = [0 for i in A]
    max_index = 0

    # iterate
    for i in range(1, len(A)):
        if M[i - 1] > 0:
            M[i] = M[i - 1] + A[i]
            T[i] = T[i - 1]
        else:
            M[i] = A[i]
            T[i] = i
        if i != max_index and M[max_index] < M[i]:
            max_index = i

    # output
    print "maximum sum:", M[max_index]
    print "subsequence: %r" % A[T[max_index]:max_index + 1]

if __name__ == '__main__':
    for line in sys.stdin:
        A = []
        for num in line.strip().split(' '):
            A.append(float(num))
        solution(A)
