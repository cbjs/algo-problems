#!/usr/bin/env python

class ZigZag(object):

    def longestZigZag(self, sequence):
        n = len(sequence)
        neg = [None] * n
        pos = [None] * n
        nl = 0
        pl = 0

        for i in range(n):
            # update neg 
            j = pl - 1
            while j >= 0 and (pos[j] == None or pos[j] >= sequence[i]):
                j -= 1
            if j + 2 > nl:
                nl = j + 2
                neg[j + 1] = sequence[i]
            elif neg[j + 1] < sequence[i]:
                neg[j + 1] = sequence[i]

            # update pos
            j = nl - 1
            while j >= 0 and (neg[j] == None or neg[j] <= sequence[i]):
                j -= 1
            if j + 2 > pl:
                pl = j + 2
                pos[j + 1] = sequence[i]
            elif pos[j + 1] > sequence[i]:
                pos[j + 1] = sequence[i]

        return max(nl, pl)

if __name__ == '__main__':
    solution = ZigZag()
    sequence = [44, 88]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))

    sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))

    sequence = [1, 7, 4, 9, 2, 5]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))

    sequence = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))

    sequence = [374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
               600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
               67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
               477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
               249, 22, 176, 279, 23, 22, 617, 462, 459, 244]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))

    sequence = [ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5,
                1000, 32, 32 ]
    print "longestZigZag(%r) = %d" % (sequence, solution.longestZigZag(sequence))
