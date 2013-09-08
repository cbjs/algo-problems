#!/usr/bin/env python
#coding:utf-8

def lcsub(str_a, str_b):
    """
        最长公共连续子串, 要求是连续的
        max_len[i, j]表示str_a[:i], str_b[:j]分别以i, j位置结尾的最长公共子串
            max_len[i, j] = max_len[i - 1, j - 1] + 1, if str_a[i] == str_b[j]
            max_len[i, j] = 0, if str_a[i] != str_b[j]

        用max_lcs_len记录找到的最大长度
        用max_lcs_i记录下标位置
    """
    # init
    max_len = {}
    max_len[(-1, -1)] = 0
    for i in range(len(str_a)):
        max_len[(i, -1)] = 0
    for j in range(len(str_b)):
        max_len[(-1, j)] = 0

    max_lcs_len = 0
    max_lcs_i = -1

    # iterate
    for i in range(len(str_a)):
        for j in range(len(str_b)):
            if str_a[i] == str_b[j]:
                max_len[(i, j)] = max_len[(i - 1, j - 1)] + 1
            else:
                max_len[(i, j)] = 0

            if max_lcs_len < max_len[(i, j)]:
                max_lcs_len = max_len[(i, j)]
                max_lcs_i = i

    # output
    print "longest_common_substring length: ",  max_lcs_len
    print "one of longest_common_substring str: ", str_a[i - max_lcs_len + 1 : i + 1]

if __name__ == '__main__':
    str_a = 'abcdefghi'
    str_b = 'cadcdabghi'
    lcsub(str_a, str_b)
