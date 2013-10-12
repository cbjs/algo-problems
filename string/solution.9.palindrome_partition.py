#!/usr/bin/env python
#coding:utf-8

def palindrome_partition(s):
    # preprocess
    s = '#' + '#'.join(s) + '#'
    n = len(s)

    # compute palindrome radius at each pos
    radius = [0] * n
    rm_center = 0
    rm_border = 0
    for i in range(n):
        if i < rm_border:
            radius[i] = min(radius[2 * rm_center - i], rm_border - i)

        while i + radius[i] + 1 < n and i - radius[i] - 1 >= 0 and s[i + radius[i] + 1] == s[i - radius[i] - 1]:
            radius[i] += 1

        if i + radius[i] > rm_border:
            rm_border = i + radius[i]
            rm_center = i

    # compute all partition
    partition = [[] for i in range(n)]
    for i in reversed(range(n)):
        for j in range(i, i + (n - i - 1) / 2 + 1):
            if radius[j] >= j - i:
                pal = s[i : 2 * j - i + 1]
                if 2 * j - i + 1 < n:
                    for part in partition[2 * j - i + 1]:
                        part_copy = part[:]
                        part_copy.append(pal)
                        partition[i].append(part_copy)
                else:
                    partition[i].append([pal])

    # strip '#'
    result = set()
    for part in partition[0]:
        strip_part = []
        for pal in part:
            strip_pal = pal.replace('#', '')
            if len(strip_pal):
                strip_part.append(strip_pal)
        result.append(strip_part)
    return 

if __name__ == '__main__':
    s = 'abbacde'
    partition = palindrome_partition(s)
    for part in partition:
        print part
