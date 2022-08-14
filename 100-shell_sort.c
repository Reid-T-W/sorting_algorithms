#include "sort.h"
#include <stdio.h>
/**
 *shell_sort - sorts an array using shell sort algo
 *@array: array to be sorted
 *@size: size of array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int i = 0;
	int temp;
	size_t j;

	if (size < 2)
	{
		return;
	}
	/*Getting the starting point for gap*/
	/*Getting the maximum gap*/
	while (gap <= size / 3)
	{
		gap = (gap * 3) + 1;
	}
	while (gap > 0)
	{
		/*j = i + gap;*/
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i] > array[i + gap])
				{
					/*Swap the two elements*/
					temp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = temp;
				}
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
