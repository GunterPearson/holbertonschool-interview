#!/usr/bin/env python3
"""Island perimeter"""


def island_perimeter(grid):
    """Returns Island perimeter of grid

    Args:
        grid ([2x2 matrix]): [contains island of ones]
    """
    total = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                total += 4
                if x != 0 and grid[x - 1][y] == 1:
                    total -= 2
                if y != 0 and grid[x][y - 1] == 1:
                    total -= 2
    return total
