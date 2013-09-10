#!/usr/bin/env python
#coding:utf-8

def mrr(string):
    """
        字符串的循环最小表示
        rs(i)表示以i开始的循环字符串, rs(i, k)表示rs(i)中每k个字符

        朴素解法，设置两个指针i, j分别从i = 0, j = 1开始比较以i, j开始的循环串
            若rs(i) < rs(j) i = j, j++; 否i不变，j++
            复杂度为O(n^2)

        改进解法, 分析
            在比较rs(i)和rs(j)的过程中，不妨设在第k次比较时rs(i, k) > rs(j, k)
            则可以看出,
                对所有的循环字符串对rs(i + x), rs(j + x), 0 <= x <= k
                都有rs(i + x) > rs(j + x)
                因此，i可以直接跳过k个字符, i += (k + 1)
            时间复杂度为O(n)
    """
    n = len(string)
    i = 0
    j = 1

    while i < n and j < n:
        # 比较
        k = 0
        while string[(i + k) % n] == string[(j + k) % n] and k < n:
            k += 1

        # 跳过比较
        if string[(i + k) % n] > string[(j + k) % n]:
            i += (k + 1)
            if i == j:  # trick, 如果相等，向前移动一下
                i += 1
        else:
            j += (k + 1)
            if j == i:
                j += 1

    k = min(i, j)
    print "found minimum_repetition_repr at index: %d" % k
    print "minimum_repetition_repr for %s : %s" % (string, string[k:] + string[:k])

if __name__ == '__main__':
    string = "badaacadgakfadfaababadasfnb"
    mrr(string)

    string = "aaaaaaaaaaa"
    mrr(string)
