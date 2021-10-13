#include "sort.h"

/**
 * merge - merge sorting algorithm function.
 * @sub: sub array
 * @buffer: buffer
 * @lo: low
 * @mid: mid
 * @hi: high
 */
void merge(int *sub, int *buffer, size_t lo, size_t mid, size_t hi)
{
	size_t low;
	size_t midd;
	size_t a = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + lo, mid - lo);
	printf("[right]: ");
	print_array(sub + mid, hi - mid);

	for (low = lo, midd = mid; low < mid && midd < hi; a++)
	{
		if (sub[low] < sub[midd])
		{
			buffer[a] = sub[low++];
		}
		else
		{
			buffer[a] = sub[midd++];
		}
	}
	for (; low < mid; low++)
	{
		buffer[a++] = sub[low];
	}
	for (; midd < hi; midd++)
	{
		buffer[a++] = sub[midd];
	}
	for (low = lo, a = 0; low < hi; low++)
	{
		sub[low] = buffer[a++];
	}
	printf("[Done]: ");
	print_array(sub + lo, hi - lo);
}

/**
 * recur - recursion help
 * @sub: sub array
 * @buffer: buffer
 * @lo: low
 * @hi: high
 */
void recur(int *sub, int *buffer, size_t lo, size_t hi)
{
	size_t mid;

	if (hi - lo > 1)
	{
		mid = lo + (hi - lo) / 2;
		recur(sub, buffer, lo, mid);
		recur(sub, buffer, mid, hi);
		merge(sub, buffer, lo, mid, hi);
	}
}

/**
* merge_sort - merge sort algorithm implementation
* @array: array to sort
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	recur(array, temp, 0, size);

	free(temp);
}
