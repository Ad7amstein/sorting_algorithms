#include "sort.h"
#include "_swap.c"
#include <unistd.h>

/**
 * partition - lomuto partition.
 *
 * @array: array to be patitioned
 * @lo: first index
 * @hi: seconde index
 *
 * Return: pivot position.
 */
size_t partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo - 1, j;

	for (j = lo; j < hi; ++j)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
				_swap(array, j, i, size);
		}
	}
	i++;
	if (i != hi)
		_swap(array, i, hi, size);

	return (i);
}

/**
 * quicksort - quick sort algorithm
 *
 * @array: array to be sortd
 * @lo: left index
 * @hi: right index
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, lo, hi, size);
	quicksort(array, lo, p - 1, size);
	quicksort(array, p + 1, hi, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
