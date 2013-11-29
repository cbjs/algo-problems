#!/usr/bin/env python
#coding: utf-8

num_map = {
    u'一': 1,
    u'二': 2,
    u'三': 3,
    u'四': 4,
    u'五': 5,
    u'六': 6,
    u'七': 7,
    u'八': 8,
    u'九': 9,
}

unit_set = [
    (u'亿', 10 ** 8),
    (u'万', 10 ** 4),
    (u'千', 10 ** 3),
    (u'百', 10 ** 2),
    (u'十', 10),
]

def trans(big):
    for unit in unit_set:
        u = unit[0]
        v = unit[1]
        i = big.find(u)
        if i != -1:
            if i == 0 or big.count(u) > 1:
                return -1

            high = trans(big[0: i])
            if high == -1:
                return - 1

            if i + 1 < len(big) and big[i + 1] == u'零':
                low = trans(big[i + 2:])
                if low >= v / 10 or low == 0:
                    return -1
            else:
                low = trans(big[i + 1:])

            if low == -1:
                return -1

            return high * v + low

    n = len(big)
    if 0 == n:
        return 0

    if n > 1 or not big in num_map:
        return -1

    return num_map[big]

if __name__ == '__main__':
    big = u'五万八千九百二十一'
    print '%s = %d' % (big, trans(big));

    big = u'五万零九百二十一'
    print '%s = %d' % (big, trans(big));

    big = u'五万零二十'
    print '%s = %d' % (big, trans(big));

    big = u'五万零一'
    print '%s = %d' % (big, trans(big));

    big = u'八千九百二十一万八千九百二十一亿八千九百二十一万八千九百二十一'
    print '%s = %d' % (big, trans(big));

    big = u'八亿'
    print '%s = %d' % (big, trans(big));

    big = u'八百亿'
    print '%s = %d' % (big, trans(big));

    big = u'八亿零一'
    print '%s = %d' % (big, trans(big));

    big = u'八百零八十'
    print '%s = %d' % (big, trans(big));

    big = u'八百八百'
    print '%s = %d' % (big, trans(big));

    big = u'八亿零'
    print '%s = %d' % (big, trans(big));

    big = u'八亿零零一'
    print '%s = %d' % (big, trans(big));
