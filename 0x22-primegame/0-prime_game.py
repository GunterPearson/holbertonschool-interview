#!/usr/bin/python3
"""Prime game - Holberton School"""

def isWinner(x, nums):
    """where x is the number of rounds and nums is an array of n"""
    for i in range(x):
        nums.remove(min(nums))
        if len(nums) == 1:
            if nums[0] % 2 == 0:
                return "Maria"
            else:
                return "Ben"
    return 0
