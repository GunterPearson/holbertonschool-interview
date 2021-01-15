#ifndef SAND_PILE
#define SAND_PILE

#include <stdlib.h>
#include <stdio.h>

static void print_grid(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

int grid1_stable(int grid1[3][3], int flags[3][3]);

void topple(int grid1[3][3], int i, int j);

#endif
