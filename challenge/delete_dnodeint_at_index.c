#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	/* Əgər silinməli olan düyün ilk düyündürsə (index 0) */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* Göstərilən indeksə qədər siyahı üzrə irəliləyirik */
	for (i = 0; tmp != NULL && i < index; i++)
		tmp = tmp->next;

	/* Əgər indeks siyahının uzunluğundan böyükdürsə */
	if (tmp == NULL)
		return (-1);

	/* Əlaqələri (pointers) yeniləyirik */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	free(tmp);
	return (1);
}
