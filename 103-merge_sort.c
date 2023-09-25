#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 *
 * @array: array to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *B;

	if (array == NULL || size < 2)
		return;

	B = malloc(sizeof(int) * size);
	if (B == NULL)
		return;

	copy_array(array, B, size);
	top_down_split_merge(array, B, 0, size);
	copy_array(B, array, size);
	free(B);
}

/**
 * copy_array - copies one array to another.
 *
 * @A: first array to copy from.
 * @B: second array to copy to.
 * @size: size of the array.
 */
void copy_array(int *A, int *B, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		B[i] = A[i];
}

/**
 * top_down_split_merge - split the array.
 *
 * @A: first array.
 * @B: second array.
 * @iBegin: the beginning.
 * @iEnd: the end.
 */
void top_down_split_merge(int *A, int *B, size_t iBegin, size_t iEnd)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1)
		return;

	iMiddle = (iBegin + iEnd) / 2;
	top_down_split_merge(A, B, iBegin, iMiddle);
	top_down_split_merge(A, B, iMiddle, iEnd);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(B + iBegin, iMiddle - iBegin);
	printf("[right]: ");
	print_array(B + iMiddle, iEnd - iMiddle);
	top_down_merge(A, B, iBegin, iMiddle, iEnd);
	printf("[Done]: ");
	print_array(B + iBegin, iEnd - iBegin);
}

/**
 * top_down_merge - sort the array.
 *
 * @A: first array.
 * @B: second array.
 * @iBegin: the begging.
 * @iMiddle: the middle.
 * @iEnd: the end.
 */
void top_down_merge(int *A, int *B, size_t iBegin, size_t iMiddle,
		size_t iEnd)
{
	size_t i = iBegin, j = iMiddle, k;

	for (k = iBegin; k < iEnd; ++k)
	{
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
}

