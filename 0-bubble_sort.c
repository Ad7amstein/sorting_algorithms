#include "sort.h"
#include "_swap.c"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: array size.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int swapped = 1;

	if (array == NULL || size < 2)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < size - j; ++i)
		{
			if (array[i] < array[i - 1])
			{
				_swap(array + i, array + i - 1);
				print_array(array, size);
				swapped = 1;
			}
		}
		j++;
	}
}

