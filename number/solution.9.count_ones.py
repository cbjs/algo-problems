#!/usr/bin/env python
#coding:utf-8

def count_ones(n):
    """
    """
    num = n
    factor = 1
    lower_num = high_num = cur_num = 0
    count = 0

    while True:

        lower_num = num % factor
        cur_num = (num / factor) % 10
        high_num = num / (factor * 10)

        if cur_num == 0 and high_num == 0:
            break

        if cur_num == 0:
            count += high_num * factor
        elif cur_num == 1:
            count += high_num * factor + lower_num + 1
        else:
            count += (high_num + 1) * factor

        factor *= 10

    print "ones of %d: %d" % (n, count)

if __name__ == '__main__':
    count_ones(13)
    count_ones(23)
    count_ones(2345)
