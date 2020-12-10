#!/usr/bin/python3
""" lock Boxes"""


def canUnlockAll(boxes):
    """ function to check if box can be unlocked"""
    keys = set()
    for i in range(len(boxes)):
        if i not in keys and i != 0:
            return False
        for elem in boxes[i]:
            if elem < len(boxes):
                keys.update(boxes[elem])
        keys.update(boxes[i])
    return True
