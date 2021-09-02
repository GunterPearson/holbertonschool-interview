#include "search_algos.h"

/**
 * print_a - Prints an array recursibely
 * @array: Pointer
 * @ind: Index
 * @size: Size
 */
void print_a(int *array, size_t ind, size_t size)
{
	if (ind > size)
		return;
	printf("%d", array[ind]);
	if (ind < size)
		printf(", ");
	print_a(array, ind + 1, size);
}

/**
 * advanced_binary - Searches for a value in a sorted array
 *
 * @array: Pointer
 * @size: Number of elements
 * @value: value for search
 *
 * Return: Index or Null
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t half;

	if (!array)
		return (-1);
	while (low <= high)
	{
		printf("Searching in array: ");
		print_a(array, low, high);
		printf("\n");

		half = (low + high) / 2;
		if (array[half] == value && array[half - 1] != value)
			return (half);
		else if (array[half] < value)
			low = half + 1;
		else
			high = half;
	}
	return (-1);
}
