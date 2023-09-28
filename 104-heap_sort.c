#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform the sift-down operation on a max-heap
 * @array: The array representing the max-heap
 * @size: The size of the max-heap
 * @root: The root index of the subtree to sift down
 */
void sift_down(int *array, size_t size, size_t root)
{
	size_t max = root;
	size_t left_child = 2 * root + 1;
	size_t right_child = 2 * root + 2;

	if (left_child < size && array[left_child] > array[max])
		max = left_child;

	if (right_child < size && array[right_child] > array[max])
		max = right_child;

	if (max != root)
	{
		/* Swap the root with the max element */
		int temp = array[root];

		array[root] = array[max];
		array[max] = temp;

		/* Recursively sift down the affected subtree */
		sift_down(array, size, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/* Build the max-heap */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i);
	}

	print_array(array, size);  /* Print the initial array */

	/* Extract elements one by one and perform sift-down */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root (maximum element) with the last element */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		/* Perform sift-down on the reduced heap */
		sift_down(array, i, 0);
	}
}
