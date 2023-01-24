#include "sort.h"

void swap(int a, int b);
int partition(int *array, int ub, int lb);
void quicker(int *array, int lb, int ub);

/**
 * quick_sort - algorithm to sorts array of ints
 *
 * @array: to be sorted
 * @size: of array
 * Return: None
*/

void quick_sort(int *array, size_t size)
{
	int lb, ub;

	if (size < 2)
		return;

	lb = array[0];
	ub = array[size - 1];

	quicker(array, lb, ub);
}

int partition(int *array, int ub, int lb)
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
			swap(array[start], array[end]);
	}
	swap(array[start], array[end]);
	return (end);
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quicker(int *array, int lb, int ub)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, ub, lb);
		quicker(array, lb, loc - 1);
		quicker(array, loc + 1, ub);
	}
}
