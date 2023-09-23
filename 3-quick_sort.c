#include "sort.h"
#include "swap.c"


/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * Return: The final pivot position.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low ; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	i++;
	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}
/**
 * lomuto_sort - Implement the quicksort algorithm using Lomuto partition.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The low index of the partition to be sorted.
 * @high: The high index of the partition to be sorted.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, pivot_idx - 1);
		lomuto_sort(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
