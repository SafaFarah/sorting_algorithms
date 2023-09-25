#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list by insertion sort algorithm
 *
 * @list: The pointer to  list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *key;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	key = (*list)->next;
	while (key != NULL)
	{
		if (key->prev->n > key->n)
		{
			temp = key;
			while (temp != NULL &&
				 temp->prev != NULL &&
				 temp->prev->n > temp->n)
			{
				swap_2nodes(temp);
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
			}
			key = temp->next;
		}
		key = key->next;
	}
}

/**
 * swap_2nodes - swaps 2 nodes in a doubly linked list.
 * @temp: the node to swap.
 */
void swap_2nodes(listint_t *temp)
{
	if (temp->prev->prev == NULL)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next = temp->prev;
		temp->prev = NULL;
		temp->next->prev = temp;
	}
	else if (temp->next == NULL)
	{
		temp->prev->prev->next = temp;
		temp->next = temp->prev;
		temp->prev = temp->prev->prev;
		temp->next->prev = temp;
		temp->next->next = NULL;
	}
	else if (temp->next == NULL && temp->prev->prev == NULL)
	{
		temp->prev->next = NULL;
		temp->prev->prev = temp;
		temp->next = temp->prev;
		temp->prev = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next = temp->prev;
		temp->prev->prev->next = temp;
		temp->prev = temp->prev->prev;
		temp->next->prev = temp;
	}
}
