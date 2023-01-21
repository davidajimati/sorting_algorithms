#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - sorts doubly-linked list using insertion sort algo.
 *
 *  @list: doubly linked list to be sorted
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	bool state = false;
	listint_t *head = NULL, *temp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	head = *list;
	while (head->next)
	{
		if (head->n > head->next->n)
		{
			head->next->prev = head->prev;
			if (head->next->prev)
				head->prev->next = head->next;
			else
				*list = head->next;

			head->prev = head->next;
			head->next = head->next->next;
			head->prev->next = head;
			if (head->next)
				head->next->prev = head;

			head = head->prev;
			print_list(*list);

			if (head->prev && head->prev->n > head->n)
			{
				if (!state)
					temp = head->next;
				state = true;
				head = head->prev;
				continue;
			}
		}
		if (!state)
			head = head->next;
		else
			head = temp, state = false;
	}
}
