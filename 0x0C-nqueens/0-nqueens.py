#!/usr/bin/python3
"""nqueens"""
import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    size = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if size < 4:
    print("N must be at least 4")
    exit(1)


def nqueens(size, y, queens):
    """nqueens"""
    for x in range(size):
        hold = 0
        for q in queens:
            if x == q[1]:
                hold = 1
                break
            if y - x == q[0] - q[1]:
                hold = 1
                break
            if x - q[1] == q[0] - y:
                hold = 1
                break
        if hold == 0:
            queens.append([y, x])
            if y != size - 1:
                nqueens(size, y + 1, queens)
            else:
                print(queens)
            del queens[-1]


nqueens(size, 0, [])
