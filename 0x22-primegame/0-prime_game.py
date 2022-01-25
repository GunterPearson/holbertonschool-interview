#!/usr/bin/python3
"""Prime game - Holberton School"""


def isWinner(x, nums):
    """where x is the number of rounds and nums is an array of n"""
    for i in range(x):
        if x == 1 and nums[i] == 1:
            return "Ben"
        nums.remove(min(nums))
        if len(nums) == 1:
            if nums[0] % 2 == 0:
                return "Ben"
            if nums[0] == 2 or nums[0] == 8 or nums[0] == 7:
                return "Maria"
            else:
                return "Ben"
    return "None"
