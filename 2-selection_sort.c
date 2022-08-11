#include "sort.h"
#include <stddef.h>
/**
 *selection_sort - sorts an array using selection sort algo
 *@array: array to be sorted
 *@size: size of array
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
