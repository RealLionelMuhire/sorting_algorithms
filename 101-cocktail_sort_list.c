#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the first node of the list
 * @node_a: Pointer to the first node to be swapped
 * @node_b: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next)
		node_b->next->prev = node_a;

	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to a pointer to the first node of the list
 */
void cocktail_sort_list(listint_t **list)
{

	int swapped = 1;
	listint_t *right, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		right = current->prev;
		while (right->prev != NULL)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				print_list(*list);
				swapped = 1;
			}
			else
				right = right->prev;
		}
	}
}

