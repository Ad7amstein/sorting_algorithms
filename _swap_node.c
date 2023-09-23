#include "sort.h"

/**
 * _swap_node - swaping two nodes in a doubly linked list
 * Return: void
 * @nd1: the first node
 * @nd2: the second node
*/

void _swap_node(listint_t *nd1, listint_t *nd2)
{
	if (nd1->next != NULL)
		nd1->next->prev = nd2;
	if (nd2->prev != NULL)
		nd2->prev->next = nd1;
	nd1->prev = nd2->prev;
	nd2->next = nd1->next;
	nd1->next = nd2;
	nd2->prev = nd1;
}
