#include "sort.h"
#include <stdlib.h>

void sort_engine(int *array, int low, int high, size_t size);

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

	sort_engine(array, 0, size - 1, size);
}

/**
 * sort_engine - performs the sort
 *
 * @array: subject
 * @low: lower bound
 * @high: upper bound
 * @size: of array
 * Return: Nothing
 */

void sort_engine(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;

		while (i < j)
		{
			while (array[i] <= array[pivot] && i <= high)
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
		sort_engine(array, low, j - 1, size);
		sort_engine(array, j + 1, high, size);
		print_array(array, size);
	}
}
