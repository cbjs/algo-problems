#!/usr/bin/env python
#coding:utf-8

def lcseq(str_a, str_b):
    """
    max_len[i, j]记录子串str_a[:i], str_b[:j]的最大公共子序列
        max_len[i, j] = max_len[i - 1, j - 1] + 1, str_a[i] == str_b[j]
        max_len[i, j] = max{ max_len[i - 1, j], max_len[i, j - 1]}

    back_track[i, j] 记录操作，用于回溯输出
        back_track[i, j] = 0, str_a[i] == str_b[j]
        back_track[i, j] = 1, str_a[i] != str_b[j] and max_len[i - 1, j] > max_len[i, j - 1]
        back_track[i, j] = 2, str_a[i] != str_b[j] and max_len[i - 1, j] < max_len[i, j - 1]
        // back_track[i, j] = 3, str_a[i] != str_b[j] and max_len[i - 1, j] = max_len[i, j - 1]
        // 输出多个相同长度的lcs
    """
    # init
    max_len = {}
    max_len[(-1, -1)] = 0
    for i in range(len(str_a)):
        max_len[(i, -1)] = 0
    for j in range(len(str_b)):
        max_len[(-1, j)] = 0
    back_track = {}

    # iterate
    for i in range(len(str_a)):
        for j in range(len(str_b)):
            if str_a[i] == str_b[j]:
                max_len[(i, j)] = max_len[(i - 1, j - 1)] + 1
                back_track[(i, j)] = (-1, -1)
            else:
                k = max_len[(i - 1, j)] - max_len[(i, j - 1)]
                if k > 0:
                    max_len[(i, j)] = max_len[(i - 1, j)]
                    back_track[(i, j)] = (-1, 0)
                else:
                    max_len[(i, j)] = max_len[(i, j - 1)]
                    back_track[(i, j)] = (0, -1)

    # output
    print "longest_common_subsequence length: ", max_len[(len(str_a) - 1, len(str_b) - 1)]
    i = len(str_a) - 1
    j = len(str_b) - 1
    lcseq_str = ''
    while i >= 0 and j >= 0:
        step_a, step_b = back_track[(i, j)]
        if step_a == -1 and step_b == -1:
            lcseq_str = str_a[i] + lcseq_str
        i += step_a
        j += step_b
    print "one of longest_common_subsequence: ", lcseq_str

if __name__ == '__main__':
    str_a = 'abcdefghi'
    str_b = 'cadcdabghi'
    lcseq(str_a, str_b)
