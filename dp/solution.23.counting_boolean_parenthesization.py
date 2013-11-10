#!/usr/bin/env python
#coding:utf-8

def solution(exp):
    # preprocess, split operator and boolean symbols
    fields = exp.strip().split(' ')
    S = []
    O = []
    for field in fields:
        if field == 'true':
            S.append(True)
        elif field == 'false':
            S.append(False)
        elif field == 'and':
            O.append('&')
        elif field == 'or':
            O.append('|')
        elif field == 'xor':
            O.append('^')

    # initialize 
    n = len(S)
    T = {}
    F = {}
    for i in range(n):
        if S[i]:
            T[(i, i)] = 1
            F[(i, i)] = 0
        else:
            T[(i, i)] = 0
            F[(i, i)] = 1

    # iterate
    for l in range(1, n):
        i = 0
        while i + l < n:
            j = i + l
            T[(i, j)] = 0
            F[(i, j)] = 0
            for k in range(i, j):
                TT = T[(i, k)] * T[(k + 1, j)]
                TF = T[(i, k)] * F[(k + 1, j)]
                FT = F[(i, k)] * T[(k + 1, j)]
                FF = F[(i, k)] * F[(k + 1, j)]
                if O[k] == '&':
                    T[(i, j)] += TT
                    F[(i, j)] += (TF + FT + FF)
                elif O[k] == '|':
                    T[(i, j)] += (TT + TF + FT)
                    F[(i, j)] += FF
                elif O[k] == '^':
                    T[(i, j)] += (TF + FT)
                    F[(i, j)] += (TT + FF)
            i += 1

    # result
    return T[(0, n - 1)]

if __name__ == '__main__':
    exp = 'true'
    print "'%s', %d" % (exp, solution(exp))

    exp = 'false'
    print "'%s', %d" % (exp, solution(exp))

    exp = 'true and false'
    print "'%s', %d" % (exp, solution(exp))

    exp = 'true and false xor true'
    print "'%s', %d" % (exp, solution(exp))

    exp = 'true or false xor true'
    print "'%s', %d" % (exp, solution(exp))

    exp = 'true and false xor true or false and true'
    print "'%s', %d" % (exp, solution(exp))
