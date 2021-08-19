#!/usr/bin/python3
"""RAIN"""


from operator import mul


def rain(walls):
    """Return: Integer indicating total amount of rainwater"""
    if walls == []:
        return 0
    len_x = walls[0]
    multiply = 0
    total = 0
    set = 0
    for num, x in enumerate(walls):
        if num == 0 and x == 0:
            continue
        else:
            if x != 0:
                if set != 0 and set <= x:
                    total += set * multiply
                    multiply = 0
                elif set != 0 and set > x:
                    total += x * multiply
                    multiply = 0
                set = x
            if x == 0:
                multiply += 1
    return total
