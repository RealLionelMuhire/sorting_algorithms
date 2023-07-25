#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;
		temp = current;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			temp = insertion_point->prev;
			insertion_point->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion_point;
			current->next = insertion_point;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			insertion_point = temp;
			print_list(*list);
		}

		current = current->next;
	}
}

