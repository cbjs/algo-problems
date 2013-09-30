#!/usr/bin/env python
#coding:utf-8

def solution(cards):
    """
        分析:
            cards中只有两张时, 玩家A先手，选较大的即可
            cards中有四张时，c1, c2, c3, c4
                玩家A选择c1时，B选择c2, 剩下c3, c4。A可以获得价值c1 + max(c3, c4)
                               B选择c4, 剩下c2, c3。A可以获得价值c1 + max(c2, c3)
                假设B够聪明，A选择c1时可以获得最小价值frist_choice, c1 + min(max(c3, c4), max(c2, c3))

                玩家A选择c4时，B选择c1, 剩下c2, c3。A可以获得价值c4 + max(c2, c3)
                               B选择c3, 剩下c1, c2。A可以获得价值c4 + max(c1, c2)
                同理，A选择c4时可以获得最小价值last_choice, c4 + min(max(c2, c3), max(c1, c2))

                玩家A应该选择最大最小价值，若first_choice大于last_choice时，选择c1，否则选c4

        动规解:
        cards[i, j]表示cards中从i到j(闭区间)的子序列。

        C[i, j]表示, 当只剩下cards[i, j]时, 玩家A应该做出的选择,
    C[i, j] = 1 表示取第一张，C[i, j] = -1 表示取最后一张。

        V[i, j]表示，玩家一从cards[i, j]中可以获得的最大最小价值。
            V[i, j] = 
                max(cards[i] + min(V[i + 1, j - 1], V[i + 2, j]),
                    cards[j] + min(V[i, j - 2], V[i + 1, j - 1])
    """
    V = {}
    C = {}
    l = 2   # 序列长度
    while l <= len(cards):
        for i in range(len(cards)):
            j = i + l - 1

            if j >= len(cards):
                break

            first_choice = cards[i]
            last_choice = cards[j]
            if l > 2:
                first_choice += min(V[(i + 1, j - 1)], V[(i + 2, j)]) 
                last_choice += min(V[(i, j - 2)], V[(i + 1, j - 1)])

            if first_choice > last_choice:
                V[(i, j)] = first_choice
                C[(i, j)] = 1
            else:
                V[(i, j)] = last_choice
                C[(i, j)] = -1 
        l += 2  # 序列长度+2

    return C

if __name__ == '__main__':
    cards = [80, 100, 10, 20, 90, 30]
    print solution(cards)
