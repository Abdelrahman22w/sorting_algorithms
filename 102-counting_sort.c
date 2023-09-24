#include "sort.h"
/*
 * get_max - get the maximum number in the array
 * @array: array to be sorted
 * @size: the size of the array
 * Return: the maximum number in the array
 */
int get_max(int *array, int size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers
 *                 using the counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void counting_sort(int *array, int size)
{
	int max, *count_arr, *sorted_arr, i;

	max = get_max(array, size);
	count_arr = (int *)malloc(sizeof(int) * (max + 1));
	sorted_arr = (int *)malloc(sizeof(int) * size);
	if (array == NULL || size < 2)
	{
		return;
	}
	if (count_arr == NULL || sorted_arr == NULL)
	{
		perror("Memory allocation failed");
		free(count_arr);
		free(sorted_arr);
		return;
	}
	for (i = 0; i <= max; i++)
	{
		count_arr[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count_arr[array[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}
	print_array(count_arr, max + 1);
	for (i = size - 1; i >= 0; i--)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = sorted_arr[i];
	}
	free(count_arr);
	free(sorted_arr);
}
