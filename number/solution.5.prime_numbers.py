#!/usr/bin/env python
#coding:utf-8
#
#   线性素数筛选算法
#   
#       每个数可以分解为 n = p1^n1 * p2^n2 * ... * pm^nm (p1 < p2 < .. < pm为素数)
#       
#       算法保证1..n中每个合数被其最小的素因子筛选出来，且只被标记一次    

def solution(n):
    not_prime = [False] * (n + 1)
    
    primes = []

    for i in range(2, n + 1):
        if not not_prime[i]:
            primes.append(i)

        for p in primes:
            if p * i > n:
                break

            # 标记为合数
            not_prime[p * i] = True

            # 每个合数被最小素因子标记，且只被标记一次
            if i % p == 0:
                break

    for p in primes:
        print p,

if __name__ == '__main__':
    solution(1000)
