#include "lists.h"


/**
 * check_cycle - check if list is a cycle
 * @list: listint_t list
 *
 * Return: 1 or 0
 */
int check_cycle(listint_t *list)
{
	const listint_t *temp;
	int x;

	temp = list;
	x = 0;
	while (temp != NULL)
	{
		if (x == 10)
		{
			return (1);
		}
		temp = temp->next;
		x++;
	}

	return (0);
}
