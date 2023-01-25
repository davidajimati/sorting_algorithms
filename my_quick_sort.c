#include "sort.h"

void sort_engine(int *array, int b, int ub, size_t size);
void swap(int *array, int loc_a, int loc_b);
int lomuto_partition(int *array, int lb, int ub);

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
 * Return: Pivot
 */

int lomuto_partition(int *array, int lb, int ub)
{
}

/**
 * sort_engine - performs the sort
 *
 * @array: subject
 * @lb: lower bound
 * @ub: upper bound
 * Return: Nothing
 */
void sort_engine(int *array, int lb, int ub, size_t size)
{
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
