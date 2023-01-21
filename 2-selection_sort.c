#include "sort.h"

/**
 * selection_sort - algorithm to sorts an array of ints in ascending order
 *
 * @array: to be sorted
 * @size: size of array
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, loc;
	bool state = false;
	int next, search;

	for (i = 0; i < size; i++)
	{
		next = array[i];
		search = array[i];
		j = 1;
		for (j += i; j < size; j++)
		{
			if (array[j] < search)
			{
				search = array[j];
				state = true;
				loc = j;
			}
		}
		if (state == true)
		{
			array[i] = search;
			array[loc] = next;
			print_array(array, size);
		}
		state = false;
	}
}
