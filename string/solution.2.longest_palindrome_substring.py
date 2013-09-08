#!/usr/bin/env python
#coding:utf-8
#
#   对字符串预处理，
#       bananas -> #b#a#n#a#n#a#s#
#       cabbad  -> #c#a#b#b#a#d#
#   将所有回文串变成奇数串, 辅助字符选择串中没有出现的字符"#"
#
#   从左向右计算
#   radius[i]记录以下标i为中心的最大回文串半径
#   最右回文串，当前找到的所有回文串中最靠右的
#   cur_i_right记录当前找到最右回文串的中心下标
#   cur_ps_right记录当前最右回文串的最右边字符下标(cur_i_right + radius[cur_i_right] - 1)
#
#   优化方法，跳过部分匹配, 如果当前下标i字符在已经找到的最右回文串P的下标范围内
#       可以用i在P中对称位置j(2 * cur_i_right - i)的回文半径radius[j]来优化
#       如果以j为中心的回文串是P的一个字串，直接跳过radius[j]
#       如果以j为中心的回文串不是P的字串(超出P的范围), 跳过cur_ps_right - i + 1

def lps(src_str):
    # preprocess
    input_str = '#'.join(src_str)
    input_str = '#' + input_str + '#' 

    # initialize
    radius = [1] * len(input_str)
    cur_i_right = 0
    cur_ps_right = 0
    max_radius = 1

    # iterate
    for i in range(1, len(input_str)):
        # skip some char match
        if cur_ps_right > i:
            radius[i] = min(radius[2 * cur_i_right - i], cur_ps_right - i + 1)

        # match begin
        while i + radius[i] < len(input_str) and i - radius[i] >= 0 and input_str[i + radius[i]] == input_str[i - radius[i]]:
            radius[i] += 1

        if i + radius[i] - 1 > cur_ps_right:
            cur_i_right = i
            cur_ps_right = cur_i_right + radius[cur_i_right] - 1

        if max_radius < radius[i]:
            max_radius = radius[i]

    # output
    print "%s lps length: %d" % (src_str, max_radius - 1)
    # output all palindromes
    for i in range(len(input_str)):
        if radius[i] == max_radius:
            start_index = (i - radius[i] + 1) / 2
            print "\t at %d: %s" % (start_index, src_str[start_index: start_index + max_radius - 1])

if __name__ == '__main__':
    lps("bananas")
    lps("cabbad")
    lps("bananasbananas")
