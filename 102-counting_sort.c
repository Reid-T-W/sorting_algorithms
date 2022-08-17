#include "sort.h"
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
	int *sort_array;
	int k;

	if (size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count_array = malloc(sizeof(int) * (k + 1));
	if (count_array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		count_array[array[i]] = count_array[array[i]] + 1;
	}
	for (j = 0; j < k + 1; j++)
	{
		count_array[j + 1] = count_array[j] + count_array[j + 1];
	}
	print_array(count_array, (k + 1));
	sort_array = malloc(sizeof(int) * size);
	if (sort_array == NULL)
		return;
	for (j = size - 1; j >= 0; j--)
	{
		count_array[array[j]] = count_array[array[j]] - 1;
		sort_array[count_array[array[j]]] = array[j];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sort_array[i];
	}
	free(sort_array);
	free(count_array);
}
