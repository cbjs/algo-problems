#!/usr/bin/env python
#coding:utf-8
#
#   方法一, 直接使用递归定义
#   方法二, 矩阵乘方 + 乘方计算优化
#       [F(n + 1) F(n); F(n) F(n - 1)] = [1 1;1 0]^n
#       乘方计算优化: A^13 -> 13二进制表示(1101) -> A^13 = A * A^4 * A^8
#
#   方法三，fast doubling
#       由方法二中矩阵等式可以推导出: 
#           F(2k + 1) = F(k)^2 + F(k + 1)^2
#           F(2k) = F(k) * (F(k + 1) - F(k - 1))
#                 = F(k) * (2 * F(k + 1) - F(k))
#
#   当数字很大时, 使用大数乘法算法加速

def fibonacci_recursive(n):
    # 当n很大时，可能会栈溢出
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def fibonacci_iterative(n):
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1

    k = 3
    a = 1
    b = 1
    while k < n:
        t = a + b
        a = b
        b = t
        k += 1

    return a + b

def matrix_multiply(A, B):
    """
        2x2矩阵相乘
        [1, 2, 3, 4] = [1 2; 3 4]
    """
    C = [0] * 4
    C[0] = A[0] * B[0] + A[1] * B[2]
    C[1] = A[0] * B[1] + A[1] * B[3]
    C[2] = A[2] * B[0] + A[3] * B[2]
    C[3] = A[2] * B[1] + A[3] * B[3]
    return C

def fibonacci_matrix(m):
    if m == 0:
        return 0

    M = [1, 0, 0, 1]    # 单位矩阵
    N = [1, 1, 1, 0]
    n = m - 1
    if n >= 2:
        while n != 0:
            if n & 0x01 != 0:
                M = matrix_multiply(N, M)
            N = matrix_multiply(N, N)
            n = n >> 1

    return M[0]

def fibonacci_fast_doubling(n):
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1

    k = n / 2
    a = fibonacci_fast_doubling(k)
    b = fibonacci_fast_doubling(k + 1)
    
    if n % 2 == 1:
        return a * a + b * b
    else:
        return a * (2 * b - a)

if __name__ == '__main__':
    n = 10
    print "fibonacci_recursive(%d) = %d" % (n, fibonacci_recursive(n))
    print "fibonacci_iterative(%d) = %d" % (n, fibonacci_iterative(n))
    print "fibonacci_matrix(%d) = %d" % (100, fibonacci_matrix(100))
    print "fibonacci_fast_doubling(%d) = %d" % (100, fibonacci_fast_doubling(100))
