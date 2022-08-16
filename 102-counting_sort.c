#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *counting_sort - sorts an array using counting sort algo
 *@array: array to be sorted
 *@size: size of array
 *Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j;
	int *count_array;
	int *index;
	int *sort_array;
	int k = array[0];

	if (size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count_array = malloc(sizeof(int) * (k + 1));
	for (i = 0; i < size; i++)
	{
		index = count_array + array[i];
		*index = *index + 1;
	}
	for (j = 0; j < k + 1; j++)
	{
		/*index = count_array + j;
		*(index + 1) = *index + *(index + 1);*/
		count_array[j + 1] = count_array[j] + count_array[j + 1];
	}
	sort_array = malloc(sizeof(int) * size);
	print_array(count_array, k + 1);
	for (i = 1; i <= size; i++)
	{
		count_array[array[size - i]] = count_array[array[size - i]] - 1;
		sort_array[count_array[array[size - i]]] = array[size - i];
	}
	free(count_array);
	free(sort_array);
}
