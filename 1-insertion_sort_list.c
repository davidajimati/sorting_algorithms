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
	listint_t *head = NULL;
	listint_t *temp = NULL;
	bool state = false;

	if (!list || !(*list) || !(*list)->next)
		return;

	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			head->next->prev = head->prev;

			if (head->prev)
				head->prev->next = head->next;

			head->next->next = head;

			if (head->next->next)
				head->next->next = head;

			head->next = head->next->next;
			head->prev = head->prev;
			head = head->prev;

			print_list(*list);
			state = true;

			if (head->prev && head->n < head->prev->n)
			{
				if (!state)
					temp = head->next;
				state = true;
				head = head->prev;
				continue;
			}
		}
		if (!state && head->next != NULL)
			head = head->next;
		else
		{
			head = temp;
			state = false;
		}
	}
}
