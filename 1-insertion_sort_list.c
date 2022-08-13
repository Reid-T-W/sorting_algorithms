#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *s;
	listint_t *x = *list;
	listint_t *x2 = *list;
	listint_t *x3;

	if ((list == NULL) || ((*list)->next == NULL))
	{
		return;
	}
		x = x->next;
		s = x;
		x3 = x->next;
		x2 = x->prev;
	while (x != NULL)
	{
		while (x2 != NULL)
		{
			if (x2->n > x->n)
			{
				s = x2;
				swap(list, s, x);
				x2 = x;
				print_list(*list);
			}
			x2 = x2->prev;
		}
		x = x3;
		s = x;
		if (x != NULL)
		{
			x3 = x->next;
			x2 = x->prev;
		}
	}
}

/**
 * swap - This function swaps two nodes
 * @list: linked list
 * @s: node to swap with x
 * @x: node to swap with s
 * Return: void
 */
void swap(listint_t **list, listint_t *s, listint_t *x)
{
	if (s != x)
	{
		x->prev->next = x->next;
		if (x->next != NULL)
		{
			x->next->prev = x->prev;
		}
		if (s->prev == NULL)
		{
			s->prev = x;
			x->next = s;
			x->prev = NULL;
			*list = x;
		}
		else
		{
			x->prev = s->prev;
			s->prev->next = x;
			x->next = s;
			s->prev = x;
		}
	}
}
