#include "sort.h"
#include <stdlib.h>

void sort_engine(int *array, int b, int ub, size_t size);
void swap(int *array, int loc_a, int loc_b);
int lomuto_partition(int *array, int lb, int ub, size_t size);
int pivot_find(size_t size);

/**
 * quick_sort - sorting algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	int lb = 0;

	if (!array || size < 2)
		return;

	sort_engine(array, lb, size - 1, size);
}

/**
 * sort_engine - performs the sort
 *
 * @array: subject
 * @lb: lower bound
 * @ub: upper bound
 * @size: of array
 * Return: Nothing
 */
void sort_engine(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb >= ub)
		return;

	loc = lomuto_partition(array, lb, ub, size);
	if (lb < ub)
	{
		sort_engine(array, lb, loc - 1, size);
		sort_engine(array, loc + 1, ub, size);
	}
}

/**
 * lomuto_partition - implements partition and finds pivot
 *
 * @array: target
 * @lb: lower bound
 * @ub: upper bound
 * @size: of array
 * Return: Pivot
 */

int lomuto_partition(int *array, int lb, int ub, size_t size)
{
	int start = lb;
	int end = ub;
	int pl = pivot_find(size);
	int pivot = array[pl];

	while (start < end)
	{
		for (; array[start] <= pivot; start++);
		for (; array[ub] > pivot; end--);

		if (start != pl && end != pl)
		{
			swap(array, start, end);
			print_array(array, size);
		}
	}

	swap(array, pl, end);
	return (end);
}

/**
 * swap - swaps 2 locations in the array
 *
 * @array: subject
 * @loc_a: location 1
 * @loc_b: location 2
 */
void swap(int *array, int loc_a, int loc_b)
{
	int temp = array[loc_a];

	array[loc_a] = array[loc_b];
	array[loc_b] = temp;
}

/**
 * pivot_find - find the location of the pivot in the array
 *
 * @size: of array
 * Return: position of pivot
*/
int pivot_find(size_t size)
{
	int pl = rand() % size;

	return (pl);
}
