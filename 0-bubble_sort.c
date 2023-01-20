#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - bubble sort algorithm C implementation
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int now, next;
	bool state = false;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			now = array[j];
			next = array[j + 1];

			if (now == next)
				continue;

			else if (now > next)
			{
				array[j] = next;
				array[j + 1] = now;
				print_array(array, size);
				state = true;
			}

			else
				continue;
		}
		if (state == false)
			return;
	}
}
