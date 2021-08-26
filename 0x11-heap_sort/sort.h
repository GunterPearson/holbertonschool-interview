#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heap_sort_print(int *array, size_t size, int *array_p, size_t size_p);
void heapin(int *array, size_t size, int i, int *array_p, size_t size_p);

#endif
