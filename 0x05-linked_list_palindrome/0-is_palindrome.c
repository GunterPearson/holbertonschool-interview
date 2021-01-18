#include "lists.h"

/**
 * is_palindrome - check if linked list is palindrome
 * @head: start of linked list
 *
 * Return: 1 or 0 for true or false
 */
int is_palindrome(listint_t **head)
{
	size_t len;
	const listint_t *current;
	size_t n;
	int check;

	current = *head;
	n = 0;
	len = len_list(*head);
	while (current != NULL)
	{
		check = check_value(n + 1, len, head);
		if (check != current->n)
		{
			return (0);
		}
		current = current->next;
		n++;
	}
	return (1);
}

/**
 * check_value - check if value is palindrome
 * @x: current value
 * @l: list size
 * @head: head of list
 * Return: size_t
 */
int check_value(size_t x, size_t l, listint_t **head)
{
	const listint_t *current;
	size_t n;

	current = *head;
	n = 0;
	while (current != NULL)
	{
		if (n == (l - x))
		{
			return (current->n);
		}
		current = current->next;
		n++;
	}
	return (0);
}


/**
 * len_list - counts all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t len_list(const listint_t *h)
{
	const listint_t *current;
	unsigned int n; /* number of nodes */

	current = h;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}
