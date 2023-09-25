#include "sort.h"

/**
 * get_max - returns the maximum element of the array.
 *
 * @array: array to get the max from.
 * @size: size of the array.
 *
 * Return: the max element of the array (int).
 */
int get_max(int *array, size_t size)
{
	int max = -1;
	size_t i;

	for (i = 0; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sort using counting sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int k, *count = NULL, *output = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	k = get_max(array, size);
	count = malloc(sizeof(size_t) * (k + 1));
	output = malloc(sizeof(int) * size);

	for (i = 0; i < size; ++i)
		count[array[i]]++;

	for (i = 1; i < (size_t) (k + 1); ++i)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = size - 1; (int) i >= 0; --i)
	{
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}

	for (i = 0; i < size; ++i)
		array[i] = output[i];

	free(output);
	output = NULL;
	free(count);
	count = NULL;
}
