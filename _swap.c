#include "sort.h"

/**
 * _swap - swaps two elements.
 *
 * @array: array
 * @p1: first position.
 * @p2: second position.
 * @size: size of the array.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
