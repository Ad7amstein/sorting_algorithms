#include "sort.h"
#include "_swap_node.c"

/**
 * cocktail_sort_list - sorting using cocktail sort
 * Return: void
 * @list: the header of the list to be sorted
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *header, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	header = *list;
	tail = header;
	while (tail->next != NULL)
		tail = tail->next;

	while (tail != header && tail->next != header)
	{
		temp = header;
		while (temp != tail)
		{
			if (temp->n > temp->next->n)
			{
				_swap_node(temp->next, temp);
				if (temp == header)
					header = header->prev;
				if (temp == tail->next)
					tail = temp;
				if (header->prev == NULL)
					print_list(header);
				else
					print_list(*list);
			}
			else
				temp = temp->next;
		}
		tail = tail->prev;
		temp = tail;

		while (temp != header)
		{
			if (temp->n < temp->prev->n)
			{
				_swap_node(temp, temp->prev);
				if (temp == tail)
					tail = tail->next;
				if (temp == header->prev)
					header = temp;
				if (header->prev == NULL)
					print_list(header);
				else
					print_list(*list);
			}
			else
				temp = temp->prev;
		}
		if (header->prev == NULL)
			(*list) = header;
		header = header->next;
		temp = header;
	}

}
