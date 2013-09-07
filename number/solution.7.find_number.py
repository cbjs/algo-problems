#!/usr/bin/env python
#coding:utf-8

def find_1_in_all_3(arr):
    """
    n个数字，所有数字都出现了3次，只有一个数字仅出现了一次，找出这个数。
    将数组中每个数转换成3进制，f(arr[i], j)为数字arr[i]三进制表示中的第j位，可能值为(0, 1, 2)
    sum(f(arr, j)) % 3 就是要找的数字的3进制表示中的第j位
    """
    num_str_base_3 = []
    max_length = 0

    # 转换成3进制
    for num in arr:
        num_str = ''
        while num != 0:
            num_str += str(num % 3)
            num /= 3

        num_str_base_3.append(num_str)

        if max_length < len(num_str):
            max_length = len(num_str)

    # 计算每一位
    num_found = 0
    base = 1
    for i in range(max_length):
        sum_i = 0
        for num_str in num_str_base_3:
            if i < len(num_str):
                sum_i += int(num_str[i])
        num_found += base * (sum_i % 3)
        base *= 3

    # 输出
    print "find_1_in_all_3 : %d" % num_found



def find_2_one_in_all_two(arr):
    """
    n个数字，所有数字都出现了2次，有两个数字仅出现了一次，找出两这个数。
    按2进制位，将数组分成两部份，如果两部份数目都为奇数就输出两组的异或值
    """
    mask = 0x01

    while True:
        xor_grp_0 = 0
        xor_grp_1 = 0
        num_grp_0 = 0
        num_grp_1 = 0
        for num in arr:
            if num & mask == 0:
                num_grp_0 += 1
                xor_grp_0 ^= num
            else:
                num_grp_1 += 1
                xor_grp_1 ^= num
        
        if num_grp_0 % 2 != 0 and num_grp_1 % 2 != 0:
            print "find_2_one_in_all_two found: %d, %d" % (xor_grp_0, xor_grp_1)
            break

def lastBitOf1(n):
    """
    lastBitOf1(n)表示整数n二进制表示中最后一个1的位置, 6(0110), lastBitOf1(6) = 2(0010)
    注：结果的二进制表示中只有一个1，即为2的指数
    """
    if n == 0:
        return 0

    return n & ~(n - 1)

def find_2_one_in_all_two_method_2(arr):
    """
    假设a和b只出现了一次，则a^b != 0
    a和b在lastBitOf1(a^b)的位置上，一个为1，一个为0
    可以将a和b分开到两组中
    """
    a_xor_b = 0
    for num in arr:
        a_xor_b ^= num

    mask = lastBitOf1(a_xor_b)
    a = 0
    b = 0
    for num in arr:
        if num & mask == 0:
            a ^= num
        else:
            b ^= num

    print "find_2_one_in_all_two_method_2 found: %d, %d" % (a, b)


def find_3_one_in_all_two(arr):
    """
    n个数字，所有数字都出现了2次，有三个数字仅出现了一次，找出三这个数。
    想办法，将三个数字分成两组，找到其中一个，另外两个可以用find_2_one_in_all_two解决

    设三个数分别是a, b, c 且 x = a ^ b ^ c
    a, b, c互不相同，所以x ^ a, x ^ b, x ^ c都不为0

    那么y = lastBitOf1(x ^ a) ^ lastBitOf1(x ^ b) ^ lastBitOf1(x ^ c) 不为0
    证明:
        lastBitOf1返回的结果的二进制表示中有且仅有一个1 
        i, j, k是lastBitOf1返回的结果中任意可能的三个整数
        i ^ j 要么为0， 要么包含两个1(二进制表示), 因此 (i ^ j) ^ k 不可能为0

    假设m = lastBitOf1(y), 则x ^ a, x ^ b, x ^ c在m位置上只有一个1，其余两个为0
    证明:
        lastBitOf1(y)在m位置上为1, 只有两种情况:
            1) x ^ a, x ^ b, x ^ c三个数在m位置上有一个1，其余两个为0
            2) 三个数在m位置上都为1
        如果三个数在m位置上都为1, 则a, b, c和x在m位置上不同, 即a, b, c在m位置上相同
        如果a, b, c在m位置上都为0, 则异或结果x在m位置上也为0，矛盾
        如果a, b, c在m位置上都为1, 则异或结果x在m位置上也为1，矛盾

    因此，可以通过lastBitOf1(x ^ *), *为arr中数，将a, b, c分到两组中, 求出其中一个
    得解
    """
    a_xor_b_xor_c = 0
    for num in arr:
        a_xor_b_xor_c ^= num

    flags = 0
    for num in arr:
        flags ^= lastBitOf1(a_xor_b_xor_c ^ num)
    flags = lastBitOf1(flags)

    a = 0
    for num in arr:
        if lastBitOf1(a_xor_b_xor_c ^ num) == flags:
            a ^= num

    print "find_3_one_in_all_two: the first: %d" % a
    print "find_3_one_in_all_two: the other two:",
    arr_with_a = arr[:]
    arr_with_a.remove(a)
    find_2_one_in_all_two_method_2(arr_with_a)

if __name__ == '__main__':
    arr = [1, 2, 2, 1, 300, 1, 2, 7, 7, 7]
    find_1_in_all_3(arr)

    arr = [1, 2, 3, 4, 5, 2, 5, 4, 1, 7, 8, 7]
    find_2_one_in_all_two(arr)

    arr = [1, 2, 3, 4, 5, 2, 5, 4, 1, 7, 8, 7]
    find_2_one_in_all_two_method_2(arr)

    arr = [1, 2, 3, 4, 5, 2, 5, 4, 1, 7, 8, 100, 7]
    find_3_one_in_all_two(arr)
