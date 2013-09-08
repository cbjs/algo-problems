#!/usr/bin/env python
#coding:utf-8
#   BM string searching algorithm

def bad_char_shift(P):
    """
        计算"坏字符"表
        保存模式串中每个字符最右出现的位置
    """
    bad_char_table = {}
    for i in range(len(P)):
        bad_char_table[P[i]] = i
    return bad_char_table

def good_suffix_shift(P):
    """
        计算"好后缀"表
        n = len(P)

        先计算最长公共后缀数组, suffix[i]表示前缀子串P[0, i]的匹配的最长后缀长度
            例: abcdebc, suffix[2] = 2, 即子串P[0, 2] = 'abc'的包含最长后缀'bc', 长度为2
        计算方法为计算reverse(P)的最长公共前缀数组prefix[j], 时间复杂度O(n)
            有suffix[i] = prefix[n - 1 - i]

        假设suffix[j] = n - i, 则有good_suffix_table[i] = j
        于是good_suffix_table[n - suffix[j]] = j
        
        对good_suffix_table[i] = -1的情况, 计算后缀P[i, ]的最长前缀longest_suffix_prefix[i]
        longest_suffix_prefix[i] = max{j | suffix[j] = j + 1 and suffix[j] <= len(P[i, ]) = n - i}

        当没有一个字符匹配成功时移动到最右不是P[n - 1]的字符
    """
    # 计算suffix[i]
    n = len(P)
    prefix = lcprefix(P[::-1])
    suffix = [0] * n
    for i in range(n):
        suffix[i] = prefix[n - 1 - i]

    # print "prefix, ", prefix
    # print "suffix, ", suffix

    # 计算good_suffix_table, 后缀P[i,]在P中出现的最右位置
    good_suffix_table = [-1] * (n + 1)
    for i in range(n):
        if suffix[i]:
            good_suffix_table[n - suffix[i]] = i
    print "good_suffix_table 01:", good_suffix_table

    # 计算good_suffix_table[n]
    for i in reversed(range(n - 1)):
        if P[i] != P[n - 1]:
            good_suffix_table[n] = i
            break

    # 计算longest_suffix_prefix第二部分, 后缀P[i,]的最长前缀下标
    longest_suffix_prefix = [-1] * (n + 1)
    last_lsp = -1
    for i in reversed(range(n)):
        j = n - i - 1
        if suffix[j] == j + 1:
            last_lsp = j
        longest_suffix_prefix[i] = last_lsp

    return (good_suffix_table, longest_suffix_prefix)

def lcprefix(S):
    """
        参见problem.5.longest_common_prefix.txt & solution.5.longest_common_prefix.py
    """
    # init
    Z = [len(S)] * len(S)

    L = R = 0
    for i in range(1, len(S)):
        if i > R:
            L = R = i
            while R < len(S) and S[R - L] == S[R]:
                R += 1
            Z[i] = R - L
            R -= 1
        else:
            k = i - L
            if Z[k] < R - i + 1:
                Z[i] = Z[k]
            else:
                L = i
                while R < len(S) and S[R - L] == S[R]:
                    R += 1
                Z[i] = R - L
                R -= 1

    return Z

def bm(P, T):
    """
        BM string searching algorithm
        采用三种规则，跳过尽可能多的位置
            1. 从左向右移动模式串，从右向左比较字符
            2. “坏字符”规则, T在发生mismatch位置上的字符称为“坏字符”bad_char = P[i]
                寻找模式串中bad_char的最右出现位置j, 与T中bad_char位置重新对齐
                    模式串向右移动max{1, i - j}
                “坏字符”规则很好使，但是在字符表较小的情况下, 会移动很慢, 比如极端例子，模式串为"aaaaaa"的情况
            3. "好后缀"规则, mismatch发生后, 成功匹配了模式串后缀P[i + 1, n]
                如果P[i + 1, n] 在P中出现超过两次, 将最靠右位置的子串P[i + 1, n]与T对齐
                    例如:   T -> abcdefghijk   重新对齐后 T -> abcdefghijk 
                            P ->  bfgafg                  P ->     bfgafg
                    模式串后缀afg与T中efg匹配失败, 模式串向右移动, 将bfg与efg对齐后，重新匹配
                    要求两次出现的模式串后缀前一个字符不能相同, 如上例afg与bfg, a与b不同

                如果P[i + 1, n]在P中只出现一次(后缀), 则计算P[i + 1, n]的最长前缀
                    例如:   T -> abcdefghijk   重新对齐后 T -> abcdefghijk 
                            P ->  gfgafg                  P ->       gfgafg
    """
    bad_char_table = bad_char_shift(P)
    good_suffix_table, longest_suffix_prefix = good_suffix_shift(P)
    #   print ', '.join(P)
    #   print "bad_char_table, ", bad_char_table
    #   print "good_suffix_table, ", good_suffix_table

    n = len(P)
    m = len(T)
    align = previous_h = n - 1  # align记录P在T中右对齐位置, previous_h用于Galil Rule跳过前缀
    while align < m:
        # print "align, ", align
        i = n - 1  # 记录P中指针
        h = align  # 记录T中指针

        # 开始匹配
        while i >=0 and P[i] == T[h]:
            i -= 1
            h -= 1

        if i < 0:   # 找到一个匹配
            print "find at index:", align - n + 1
            align += n
            if n > 1:
                align -= (longest_suffix_prefix[1] + 1)
        else:   # 在P[i]处mismatch
            bad_char_shift_len = -1 if not T[h] in bad_char_table else i - bad_char_table[T[h]]
            good_suffix_shift_len = -1 if good_suffix_table[i + 1] == -1 else n - 1 - good_suffix_table[i + 1]
            if good_suffix_shift_len == -1 and longest_suffix_prefix[i + 1] != -1:
                good_suffix_shift_len = n - 1 - longest_suffix_prefix[i + 1]
            align += max(1, bad_char_shift_len, good_suffix_shift_len)

if __name__ == '__main__':
    P = 'abcbabab'
    T = 'cdababcbababdababcbababef'
    bm(P, T)
