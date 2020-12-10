#!/usr/bin/python3
""" lock Boxes"""


def canUnlockAll(boxes):
    """ function to check if box can be unlocked"""
    if boxes is None or len(boxes) <= 1:
        return True
    idx = []
    nunl = []
    for x in range(len(boxes)):
        if x not in list(set(nunl)) and x != 0:
            return False
        for y in range(len(boxes[x])):
            idx.append(boxes[x][y])
        for z in idx:
            for a in range(len(boxes[z])):
                nunl.append(boxes[z][a])
        nunl = nunl + idx
    return True
