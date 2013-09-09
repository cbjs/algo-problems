#!/usr/bin/env python
#coding:utf-8

def reverse(sentence, l, r):
    """
        reverse sentence[l, r)
    """
    while l < r - 1:
        tmp = sentence[l]
        sentence[l] = sentence[r - 1]
        sentence[r - 1] = tmp
        l += 1
        r -= 1

def solution(str_sentence):
    """
        依次翻转每个单词, 再翻转整个句
    """
    sentence = list(str_sentence)
    n = len(sentence)
    l = r = 0
    while r < n:
        while l < n and sentence[l] == ' ':
            l += 1

        r = l + 1
        while r < n and sentence[r] != ' ':
            r += 1

        if l < n and r <= n:
            reverse(sentence, l, r)
        
        l = r

    reverse(sentence, 0, n)

    return ''.join(sentence)

if __name__ == '__main__':
    s = "I'm a student."
    print "before: %s, after: %s" % (s, solution(s))
