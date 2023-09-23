#include "sort.h"

/**
 * _swap - swaps two elements.
 *
 * @array: array
 * @p1: first position.
 * @p2: second position.
 * @size: size of the array.
 */
void _swap(int *array, int p1, int p2, size_t size)
{
	int tmp;

	tmp = array[p1];
	array[p1] = array[p2];
	array[p2] = tmp;
	print_array(array, size);
}
