#include "sort.h"

/**
 * heap_sort - sorts an array of ints
 * @array: ints
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	heap_sort_print(array, size, array, size);
}

/**
 * heap_sort_print - print heap sort
 *
 * @array: array to sort
 * @size: size of array to sort
 * @array_p: array to print
 * @size_p: size of array to print
 *
 */
void heap_sort_print(int *array, size_t size, int *array_p, size_t size_p)
{
	int i = 0, temp = 0;

	for (i = (size - 1) / 2; i >= 0; i--)
	{
		heapin(array, size, i, array_p, size_p);
	}
	for (i = (size - 1); i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		array_p[i] = array[i];
		array_p[0] = array[0];
		print_array(array_p, size_p);

		heapin(array, i, 0, array_p, size_p);
	}
}

/**
 * heapin - swapping
 *
 * @array: ints
 * @size: size of array
 * @i: index
 * @array_p: ints to print
 * @size_p: size of array to print
 *
 */
void heapin(int *array, size_t size, int i, int *array_p, size_t size_p)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp = 0;

	if (left < (int)size && array[left] > array[max])
		max = left;
	if (right < (int)size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		array_p[i] = array[i];
		array_p[max] = array[max];
		print_array(array_p, size_p);

		heapin(array, size, max, array_p, size_p);
	}
}
