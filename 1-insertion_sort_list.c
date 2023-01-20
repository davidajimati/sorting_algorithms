#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - sorts using insertion sort algorithm
 *
 *  @list: doubly linked list to be sorted
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *temp = head;
	int now, next;
	bool state = false;

	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		while (head->next != NULL)
		{
			now = head->n;
			next = head->next->n;

			if (now == next)
				continue;

			else if (next > now)
			{
				temp = head;
				if (temp->prev->next != NULL)
					temp->prev->next = head->next;

				temp->next->prev = head->prev;
				temp->prev = head->next;
				temp->next = head->next->next;
				temp->next->next->prev = head;
				state = true;
				print_list(list);
			}

			else
				continue;
		}
		if (state == false)
			return;
		head = head->next;
	}
}

/**
 * this algorithm sorts the smallest to the left
 *
 * create a nested for loop
 *
 * assign 2 pointers
 * 1 to the current, the 2nd to the next
 *
 * if the 2 matches, continues,
 * else if next is smaller than current,
 * swap their positions
 *
 * print the list at every swap.
 *
 * if no more swaps, exit the loop
 *
 */
