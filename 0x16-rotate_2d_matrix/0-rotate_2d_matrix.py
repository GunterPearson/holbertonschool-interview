#!/usr/bin/python3
"""rotate 2d matrix"""


def rotate_2d_matrix(matrix):
    """rotate matrix 90 degree"""
    new = matrix[::-1]
    result = []
    tups = list(zip(*new))
    for tup in tups:
        result.append(list(tup))
    matrix[:] = result
