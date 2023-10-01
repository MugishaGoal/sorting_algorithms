#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			tmp = current->next;
			if (tmp != NULL)
				tmp->prev = prev;
			prev->next = tmp;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
