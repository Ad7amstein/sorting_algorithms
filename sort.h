#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *, int lo, int hi, size_t size);
void _swap(int *a, int *b);
int partition(int *, int lo, int hi, size_t size);
void insertion_sort_list(listint_t **list);
void _swap_node(listint_t *nd1, listint_t *nd2);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void merge_sort(int *array, size_t size);
void copy_array(int *A, int *B, size_t size);
void top_down_split_merge(int *A, int *B, size_t iBegin, size_t iEnd);
void top_down_merge(int *A, int *B, size_t iBegin, size_t iMiddle,
		size_t iEnd);

#endif /* SORT_H */

