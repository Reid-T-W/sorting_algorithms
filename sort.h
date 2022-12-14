#ifndef HEADER_SORTING
#define HEADER_SORTING
#include <stddef.h>
#include <stdbool.h>
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
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *s, listint_t *x);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void partition(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_cocktail(listint_t **list, listint_t **for_first,
			listint_t **for_second, bool *swa);
void counting_sort(int *array, size_t size);
#endif /*HEADER_SORTING*/
