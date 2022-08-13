#include "sort.h"
/**
 *quick_sort - sorts an array using quick sort algo
 *@array: array to sort
 *@size: size of array
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	partition(array, start, end, size);
}
/**
 * partition - function that partitions the array
 * @array: array/subarray to sort
 * @start: start index of subarray
 * @end: end index of subarray
 * @size: size of array
 * Return: void
 */
void partition(int *array, int start, int end, size_t size)
{
	int j;
	int pivot;
	int temp;
	int temp_val;
	/*Define termination condition*/
	if (end < start || end - start < 1)
	{
		return;
	}
	pivot = array[end];
	temp = start;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			temp_val = array[j];
			array[j] = array[temp];
			array[temp] = temp_val;
			if (temp != j)
			{
				print_array(array, size);
			}
			temp = temp + 1;
		}
	}
	temp_val = array[temp];
	array[temp] = array[end];
	array[end] = temp_val;
	if (temp != end)
	{
		print_array(array, size);
	}

	partition(array, start, temp - 1, size);
	partition(array, temp + 1, end, size);
}
