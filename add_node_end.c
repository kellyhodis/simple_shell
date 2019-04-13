#include "holberton.h"

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to head of list_t list
* @str: string to duplicate
*
* Return: address of new element or NULL if failure
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *last = *head;

	new = (list_t *)malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->next = NULL;

	if (!(*head))
	{
		new->next = (*head);
		(*head) = new;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);

}
