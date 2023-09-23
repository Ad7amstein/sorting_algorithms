#include "sort.h"
#include "_swap_node.c"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2;

	if (*list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;
	temp2 = temp->next;

	while (temp)
	{
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			_swap_node(temp, temp->prev);
			if (temp->prev == NULL)
                        	(*list) = temp;
			print_list(*list);
		}
		temp = temp2;
		if (temp2 != NULL)
			temp2 = temp2->next;
	}
}
