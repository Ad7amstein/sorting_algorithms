#include "sort.h"
#include "_swap_int.c"

/**
 * selection_sort - sorting an array with selection sort
 * Return: void
 * @array: the array pointer
 * @size: number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			_swap(array + i, array + min);
			print_array(array, size);
		}
	}
}
