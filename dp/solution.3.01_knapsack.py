#!/usr/bin/env python
#coding:utf-8
#
# 用V[i, W]表示: 前i个物品放入容量为W的背包中可以获得的最大价值,
#   V[i, W] = V[i - 1, W], 当w[i] > W时
#   V[i, W] = max{V[i - 1, W], V[i - 1, W - w[i]] + v[i]}, 当w[i] <= W时
# 
#   最终结果可以通过计算V[n, W] 得到
# 用T[i, W]表示：是否放入了第i个物品，如果是为1，没放设置为0
#
# 对V[i, W]可以做空间优化， 
#   每次迭代过程，从大到小计算
#   if w[i] < W:
#       for k from W to w[i]:
#           V[k] = max{V[k], V[k - w[i]] + v[i]}

def solution(w, v, W):
    # init
    T = {}
    V = [0] * (W + 1)

    # iterate
    for i in range(0, len(w)):
        for k in range(W, w[i] - 1, -1):
            if V[k] < (V[k - w[i]] + v[i]):
                V[k] = V[k - w[i]] + v[i] 
                T[(i, k)] = 1
            else:
                T[(i, k)] = 0

    # output
    print "max value:%d" % V[W]
    print "objects:"
    c = W
    for i in reversed(range(0, len(w))):
        if (i, c) in T and T[(i, c)] == 1:
            print "\t(%d, %d, %d)" % (i, w[i], v[i])
            c -= w[i]
        if c == 0:
            break

if __name__ == '__main__':
    w = [9, 5, 10, 37, 23, 49, 77, 150]
    v = [30, 20, 5, 1, 23, 9, 77, 150]
    W = 33
    solution(w, v, W)
