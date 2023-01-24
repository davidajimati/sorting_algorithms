#include "sort.h"

void quick_sort_rec(int *array, int lower, int higher, size_t size);
int lomuto_partition(int *array, int lower, int higher, size_t size);
/**
 * quick_sort - ...
 * @array: ...
 * @size: ...
 *
 * Return: Nothing!
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - ...
 * @array: ...
 * @lower: ...
 * @higher: ...
 * @size: ...
 *
 * Return: Nothing!
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int lop = 0;

	if (lower < higher)
	{
		lop = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, lop - 1, size);
		quick_sort_rec(array, lop + 1, higher, size);
	}
}

/**
 * lomuto_partition - ...
 * @array: ...
 * @lower: ...
 * @higher: ...
 * @size: ...
 *
 * Return: Nothing!
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pvt = 0, aux = 0;

	pvt = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pvt)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}
