#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order
 * @list: print the list after each time you swap two elements
 *
 * Return: Null
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *loop, *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;

	while (ptr != NULL)
	{
		curr = ptr;

		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			loop = curr->prev;

			if (curr->next != NULL)
				curr->next->prev = loop;
			loop->next = curr->next;
			curr->prev = loop->prev;
			curr->next = loop;

			if (loop->prev != NULL)
				loop->prev->next = curr;
			else
				*list = curr;
			loop->prev = curr;

			print_list(*list);

		}

		ptr = ptr->next;
	}
}
