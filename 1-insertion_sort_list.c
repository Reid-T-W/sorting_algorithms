#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x;
	listint_t *x2;
	listint_t *x3;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (x3 = (*list)->next; x3; x3 = x3->next)
	{
		x = x3;
		x2 = x->prev;
		while (x2 && x2->n > x->n)
		{
			if (x->next)
			{
				x->next->prev = x2;
			}
			x2->next = x->next;
			x->next = x2;
			x->prev = x2->prev;
			if (x2->prev)
			{
				x2->prev->next = x;
			}
			else
			{
				*list = x;
			}
			x2->prev = x;
			print_list(*list);
			x2 = x->prev;
		}
	}
}
