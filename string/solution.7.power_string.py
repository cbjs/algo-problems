#!/usr/bin/env python
#coding:utf-8

def power_of_string(string):
    """
        用KMP的next数组求解
        S = s ^ m

        假设字符串, next数组下标都从1开始, n = len(string)
        根据定义，next[n]表示整个字符串string的最大长缀字符串长度
            则 len(s) = n - next[n]
                m = n / len(s)
    """
    n = len(string)
    next = [0] * n

    k = 0
    for i in range(1, n):
        while k > 0 and string[k] != string[i]:
            k = next[k]

        if string[k] == string[i]:
            k += 1

        next[i] = k

    l = n - next[n - 1]
    if n % l == 0:
        m = n / l
        print "power_of_string: %s = %s ^ %d" % (string, string[:l], m)
    else:
        print "power_of_string: %s = %s ^ 1" % (string, string)

if __name__ == '__main__':
    string = "abcabcabc"
    power_of_string(string)

    string = "cdefg"
    power_of_string(string)

    string = "ababa"
    power_of_string(string)

    string = "fffffff"
    power_of_string(string)
