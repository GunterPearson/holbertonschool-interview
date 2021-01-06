#!/usr/bin/python3
""" minimum operations"""


def minOperations(n):
    """ return min # of operations"""
    copy = 1
    paste = 0
    count = 0
    if copy > n:
        return 0
    while copy < n:
        if n % copy == 0 and copy > paste:
            paste = copy
        else:
            copy += paste
        count += 1
    return count
