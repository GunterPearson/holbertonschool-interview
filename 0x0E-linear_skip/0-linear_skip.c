#include "search.h"

/**
 * inbetween - common print statement for
 * when a value is found between two indexes.
 *
 * @a: first index value
 * @b: second index value
 */
void inbetween(unsigned long a, unsigned long b)
{
	printf("Value found between indexes [%lu] and [%lu]\n", a, b);
}


/**
 * linear_skip - search a linear skip list
 * @list: skip list to search
 * @value: value to find
 * Return: address of node found, null if doesn't exist
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipprev, *skipnext, *mainptr;

	if (list == NULL)
		return (NULL);
	skipprev = list;
	skipnext = list->express;
	while (skipnext != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       skipnext->index, skipnext->n);
		if (skipnext->n >= value)
			break;
		skipprev = skipnext;
		skipnext = skipprev->express;
	}
	if (skipnext != NULL)
		inbetween(skipprev->index, skipnext->index);
	else
	{
		mainptr = skipprev;
		while (mainptr->next != NULL)
			mainptr = mainptr->next;
		inbetween(skipprev->index, mainptr->index);
	}
	mainptr = skipprev;
	while (mainptr != skipnext)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       mainptr->index, mainptr->n);
		if (mainptr->n == value)
			return (mainptr);
		mainptr = mainptr->next;
	}
	if (mainptr != NULL && mainptr->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       mainptr->index, mainptr->n);
		return (mainptr);
	}
	return (NULL);
}
