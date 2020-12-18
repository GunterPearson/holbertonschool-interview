#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: Head node of the list
 * @number: Number to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new = malloc(sizeof(listint_t));
    listint_t *curr, *next;

    if (new == NULL)
        return (NULL);
    new->n = number;
    if (head == NULL)
        return (NULL);
    if (*head == NULL)
    {
        *head = new;
        return (new);
    }
    if ((*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }
    for (curr = *head, next = curr->next; curr != NULL;
        curr = curr->next, next = next->next)
    {
        if (next == NULL || next->n >= number)
        {
            curr->next = new;
            new->next = next;
            return (new);
        }
    }
    return (NULL);
}
