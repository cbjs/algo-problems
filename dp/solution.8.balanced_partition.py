#!/usr/bin/env python
#coding:utf-8
#
#   输入为a(1..n)
#   用P[i][S]表示从前i个数中是否能构造出和为S的子集, True表示可以，False表示不可以
#   那么，
#       P[i][S] = P[i - 1][S] || P[i - 1][S - a[i]]
#
#   要求s1和s2大小相等
#   输入为a(1..2n)
#   用P[i][j][S]表示从前i个数中刚好有大小为j的子集合为S
#   那么,
#       P[i][j][S] = P[i - 1][j][S] || P[i - 1][j - 1][S - a[i]]


def solution(a):
    """构造两个集合S1和S2，使|sum(S1) - sum(S2)|最小"""
    total_sum = sum(a)

    P = [False] * (total_sum / 2 + 1)
    backtrace = {}

    P[0] = True

    for i in range(len(a)):
        for S in reversed(range(a[i], len(P))):
            if not P[S] and P[S - a[i]]:
                backtrace[(i, S)] = True
                P[S] = True

    # output
    for S in reversed(range(len(P))):
        if P[S]:
            print "min |sum(S1) - sum(S2)| = |%d - %d| = %d" % (S, total_sum - S, total_sum - 2 * S)
            break
    s1 = []
    s2 = []
    for i in reversed(range(len(a))):
        if (i, S) in backtrace:
            s1.append(a[i])
            S -= a[i]
        else:
            s2.append(a[i])
    print "s1:%r" % s1
    print "s2:%r" % s2

def solution_equal_size(a):
    n = len(a) / 2
    total_sum = sum(a)

    P = {}
    backtrace = {}
    for i in range(len(a)):
        P[(i, 0, 0)] = True
        for j in range(1, min(i + 1, n) + 1):
            for S in range(total_sum / 2 + 1):
                if (i - 1, j, S) in P:
                    P[(i, j, S)] = True
                else:
                    if S >= a[i] and (i - 1, j - 1, S - a[i]) in P:
                        P[(i, j, S)] = True
                        backtrace[(i, j, S)] = True

    # output
    for S in reversed(range(total_sum / 2 + 1)):
        if (len(a) - 1, n, S) in P:
            print "min |sum(S1) - sum(S2)| = |%d - %d| = %d" % (S, total_sum - S, total_sum - 2 * S)
            break
    s1 = []
    s2 = []
    j = n
    for i in reversed(range(len(a))):
        if (i, j, S) in backtrace:
            s1.append(a[i])
            j -= 1
            S -= a[i]
        else:
            s2.append(a[i])
    print "s1: ", s1
    print "s2: ", s2

if __name__ == '__main__':
    a = [1, 2, 3, 100, 4, 88, 5, 6, 7, 9, 2000, 8, 2050, 10]
    solution(a)
    solution_equal_size(a)
