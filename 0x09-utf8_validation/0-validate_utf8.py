#!/usr/bin/python3
""" validate utf8"""


def validUTF8(data):
    """ return based on valid"""
    for x in data:
        if x > 128:
            return False
    return True
