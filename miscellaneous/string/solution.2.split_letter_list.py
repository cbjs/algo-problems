#!/usr/bin/env python
#coding:utf-8
#
#   DP
#   min_split[i, l]表示以下标i开始，长度为l的子串的最小拆分数
#       min_split[i, l] = min{min_split[i, k] + min_split[i + k, l - k]}, k = 1 .. l - 1
#   min_split[0, n]为问题解

def SplitLetterList(s):
    n = len(s)
    if n == 1 or n == 0:
        return n

    # min_split[(i, l)]表示以下标i开始，长度为l的子串的最小拆分数
    min_split = {}
    # con_flag[i, l]表示以下标i开始，长度为l的子串是否連续, 做了空间优化去掉一维
    con_flag = []

    # 初始化,规则1
    for i in range(n):
        con_flag.append(True)
        min_split[(i, 1)] = 1

    # 应用规则2及规则3
    for i in range(n - 1):
        min_split[(i, 2)] = 2
        if s[i] == s[i + 1]:
            min_split[(i, 2)] = 1

            # 出现連續三个相同字符的情况处理, 规则3
            if i > 0 and min_split[(i - 1, 2)] == 1:
                if i + 2 < n:
                    min_split[(i - 1, 4)] = 1
                if i + 3 < n and s[i + 2] == s[i + 3]:
                    min_split[(i - 1, 5)] = 1

        # 更新连续标志数组
        con_flag[i] = False
        if ord(s[i + 1]) - ord(s[i]) == 1:
            con_flag[i] = True

    # 从底向上迭代, l为子串长度，i为子串起始下标
    for l in range(3, n + 1):
        for i in range(n):
            # 跳过以i开始，长度为l的不合法串
            if i + l > n:
                break

            # 更新连续标志数组
            if con_flag[i] and con_flag[i + 1]:
                # 应用规则4
                if l >= 5:
                    min_split[(i, l)] = 1
                    continue
            else:
                con_flag[i] = False

            # 如果(i, l)已存在，一定是规则3让min_split[(i, l)] = 1
            if not (i, l) in min_split:
                # 子问题解找最小拆分数
                min_split[(i, l)] = l
                for j in range(1, l):
                    tmp = min_split[(i, j)] + min_split[(i + j, l - j)]
                    if tmp < min_split[(i, l)]:
                        min_split[(i, l)] = tmp

    return min_split[(0, n)]

if __name__ == '__main__':
  s = "AAABBBCCC";
  print "%s, %d\n" % (s, SplitLetterList(s))
  
  s = "AAABCDEFUXYZ";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "ABCDEFG";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "A";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "AB";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "AA";
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "AAAA"
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "AAAB"
  print "%s, %d\n" % (s, SplitLetterList(s))

  s = "AAABB"
  print "%s, %d\n" % (s, SplitLetterList(s))
