#include "sort.h"
#include "_swap_int.c"

/**
 * partition - lomuto partition.
 *
 * @array: array to be patitioned
 * @lo: first index
 * @hi: seconde index
 * @size: size of the array.
 *
 * Return: pivot position.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo - 1, j;

	for (j = lo; j < hi; ++j)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				_swap(array + j, array + i);
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != hi)
	{
		_swap(array + i, array + hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * quicksort - quick sort algorithm
 *
 * @array: array to be sortd
 * @lo: left index
 * @hi: right index
 * @size: size of the array.
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
