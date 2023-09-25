#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one.
 * @array: Original array containing two sorted subarrays.
 * @temp: Temporary array for holding merged elements.
 * @left_size: Size of the left subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *temp, size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	/* Display merging information */
	printf("Merging...\n");
	printf("[Left]: ");
	print_array(array, left_size);
	printf("[Right]: ");
	print_array(array + left_size, right_size);

	/* Merge the two subarrays */
	while (i < left_size && j < right_size)
	{
		if (array[i] <= (array + left_size)[j])
			temp[k++] = array[i++];
		else
			temp[k++] = (array + left_size)[j++];
	}

	/* Copy remaining elements from the left subarray */
	while (i < left_size)
		temp[k++] = array[i++];

	/* Copy remaining elements from the right subarray */
	while (j < right_size)
		temp[k++] = (array + left_size)[j++];

	/* Copy the merged elements back to the original array */
	for (k = 0; k < left_size + right_size; k++)
		array[k] = temp[k];

	/* Display the sorted subarray */
	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * _merge_sort - Recursive function to initiate merge sort.
 * @array: Array to be sorted.
 * @temp: Temporary array for holding sorted elements.
 * @size: Size of the array.
 */
void _merge_sort(int *array, int *temp, size_t size)
{
	size_t half = size / 2;

	/* Base case: if the size is less than 2, return */
	if (size < 2)
		return;

	/* Recursively sort the left and right subarrays */
	_merge_sort(array, temp, half);
	_merge_sort(array + half, temp + half, size - half);

	/* Merge the sorted subarrays */
	merge(array, temp, half, size - half);
}

/**
 * merge_sort - Initiate merge sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	/* Check for invalid inputs */
	if (!array || size < 2)
		return;

	/* Allocate memory for the temporary array */
	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	/* Start the merge sort process */
	_merge_sort(array, temp, size);

	/* Free the temporary array */
	free(temp);
}
