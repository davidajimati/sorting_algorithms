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
	listint_t *head = *list;
	listint_t *this = NULL, *last = NULL, *after = NULL, *post_after = NULL;
	int now, next;
	bool state = false;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		while (head->next != NULL)
		{
			now = head->n;
			next = head->next->n;
			if (next < now)
			{
				this = head;
				last = head->prev;
				after = head->next;
				post_after = head->next->next;

				if (last != NULL)
					last->next = after;
				after->prev = last;
				after->prev = last;
				this->prev = after;
				if (post_after != NULL)
				{
					this->next = post_after;
					post_after->prev = this;
				}
				state = true;
				print_list(*list);
			}
			head = head->next;
		}
		if (state == false)
			return;
		head = head->next;
	}
}
