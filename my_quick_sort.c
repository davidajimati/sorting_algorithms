#include "sort.h"

void sort_engine(int *array, int b, int ub, size_t size);
void swap(int *array, int loc_a, int loc_b);
int lomuto_partition(int *array, int lb, int ub, size_t size);

/**
 * quick_sort - sorting algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	int lower = 0;
	int upper = size - 1;

	if (!array || size < 2)
		return;

	sort_engine(array, lower, upper, size);
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
	int pivot = array[lb];
	int start = lb;
	int end = ub;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;

		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			swap(array, start, end);
			print_array(array, size);
		}
	}
	swap(array, pivot, end);
	print_array(array, size);
	return (end);
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

	sort_engine(array, lb, ub, size);
	if (lb < ub)
	{
		loc = lomuto_partition(array, lb, ub, size);
		sort_engine(array, lb, loc - 1, size);
		sort_engine(array, loc + 1, ub, size);
	}
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
