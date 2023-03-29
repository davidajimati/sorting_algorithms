#include "sort.h"

void engine(int *array, int low, int upper, size_t size);

/**
 * quick_sort - sorting algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	engine(array, 0, size - 1, size);
}

/**
 * engine - does the sorting
 *
 * @array: subject
 * @low: lower boundary
 * @upper: upper boundary
 * @size: of array
 * Return: Nothing.
*/

void engine(int *array, int low, int upper, size_t size)
{
	int pivot, i, j, temp;

	if (low < upper)
	{
		pivot = low;
		i = low;
		j = upper;

		if (i < j)
		{
			while (array[i] <= array[pivot] && i <= upper)
				i++;

			while (array[j] > array[pivot] && j >= low)
				j--;

			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		temp = array[j];
		array[j] = array[pivot];
		array[pivot] = temp;

		/* initiate the recursion */
		engine(array, low, j - 1, size);
		engine(array, j + 1, upper, size);
		print_array(array, size);
}
}
