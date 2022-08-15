#include "sort.h"
#include <stdbool.h>
#include <stdio.h>
/**
 *cocktail_sort_list - sorts a doubly linked list using cocktail_sort algo
 *@list: doubly linked list to be sorted
 *
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *for_first;
	listint_t *for_second;
	bool swapped = true;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
	{
		return;
	}
	while (swapped == true)
	{
		swapped = false;
		for_first = (*list)->next;
		for_second = *list;
		while (for_first != NULL)
		{
			if ((for_first->n) < (for_second->n))
			{
				swap_cocktail(list, &for_first, &for_second, &swapped);
			}
			for_first = for_first->next;
			for_second = for_second->next;
		}
		if (swapped == false)
		{
			break;
		}
		for_first = for_second;
		for_second = for_second->prev;
		while (for_second != NULL)
		{
			swapped = false;
			if ((for_second->n) > (for_first->n))
			{
				swap_cocktail(list, &for_first, &for_second, &swapped);
			}
			for_second = for_second->prev;
			for_first = for_first->prev;
		}
	}
}

void swap_cocktail(listint_t **list, listint_t **for_first,
		   listint_t **for_second, bool *swa)
{
	listint_t *temp;

	if ((*for_second)->prev != NULL)
	{
		(*for_second)->prev->next = *for_first;
	}
	else
	{
		*list = *for_first;
	}
	(*for_first)->prev = (*for_second)->prev;
	(*for_second)->prev = *for_first;
	(*for_second)->next = (*for_first)->next;
	if ((*for_first)->next != NULL)
	{
		(*for_first)->next->prev = *for_second;
	}
	(*for_first)->next = *for_second;
	*swa = true;
	print_list(*list);
	temp = *for_first;
	*for_first = *for_second;
	*for_second = temp;
}
