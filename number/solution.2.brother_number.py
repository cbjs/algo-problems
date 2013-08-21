#!/usr/bin/env python
#coding:utf-8

def big_brother_number(number):
    """38627 -> 38672"""
    # get each digit
    nums = []
    while number != 0:
        nums.append(number % 10)
        number /= 10

    # find first decreasing position
    pos = 0
    for i in range(1, len(nums)):
        if nums[i] < nums[i - 1]:
            pos = i
            break
    if pos == 0:
        return number

    # find first bigger number than nums[pos]
    b_pos = 0
    for i in range(pos):
        if nums[i] > nums[pos]:
            b_pos = i
            break
    
    # swap
    tmp = nums[pos]
    nums[pos] = nums[b_pos]
    nums[b_pos] = tmp

    # composite big brother number
    big_brother_num = 0
    for i in range(len(nums)):
        if i < pos:
            j = pos - 1 - i
            big_brother_num += nums[j] * (10 ** i)
        else:
            big_brother_num += nums[i] * (10 ** i)

    return big_brother_num

if __name__ == '__main__':
    start_number = 38726
    while True:
        big_brother_num = big_brother_number(start_number)
        if big_brother_num == start_number:
            break
        print big_brother_num
        start_number = big_brother_num
