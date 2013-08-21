#!/usr/bin/env python
#coding:utf-8
#
#   solution 1, 子问题:
#   用V[W]表示"负重为W的背包在不超过负重的情况下，可以获取的最大价值"
#
#       V[W] = max{ V[W - w[i]] + v[i] }, i = 1,...,n
#   解题方法同找零钱
#   
#   solution 2, 子问题:
#   用V[i, W]表示"前i种物品，放入负重为W背包中，可以获取的最大价值"
#   
#       V[i, W] = max {V[i - 1, W - k * w[i]] + k * v[i]}, k = floor(W / w[i])
#

def solution_one(w, v, W):
    # init
    V = [0] * (W + 1)
    T = {}
    
    # iterate
    for j in range(1, len(V)):
        for i in range(0, len(w)):
            if w[i] <= j and V[j] < V[j - w[i]] + v[i]:
                V[j] = V[j - w[i]] + v[i]
                T[j] = i

    # output
    print "max value:%d" % V[W]
    objects_set = {}
    j = W
    while V[j] != 0:
        i = T[j]
        if not i in objects_set:
            objects_set[i] = 1
        else:
            objects_set[i] += 1
        j -= w[i]
    for i,n in objects_set.items():
        print "%d : (%d, %d) : %d" % (i, w[i], v[i], n)

def solution_two(w, v, W):
    # init
    V = [0] * (W + 1)
    T = [None] * (W + 1)

    # iterate
    for i in range(0, len(w)):
        for j in range(w[i], W + 1):
            if V[j] < V[j - w[i]] + v[i]:
                V[j] = V[j - w[i]] + v[i]
                if not T[j - w[i]]:
                    T[j] = {}
                else:
                    T[j] = T[j - w[i]].copy()
                if not i in T[j]:
                    T[j][i] = 1
                else:
                    T[j][i] += 1

    # output
    print "max value:%d" % V[W]
    for i,n in T[W].items():
        print "%d : (%d, %d) : %d" % (i, w[i], v[i], n)

if __name__ == '__main__':
    w = [1, 2, 3, 4, 5, 6]
    v = [10, 8, 31, 15, 50, 19]
    W = 10
    print "solution one:"
    solution_one(w, v, W)

    print "solution two:"
    solution_two(w, v, W)
