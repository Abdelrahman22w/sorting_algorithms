#include "sort.h"
#include "swap.c"
/**
 * selection_sort - Sort an array of integers in ascending order
 *                  by selection algo
 * @array: An array of integers
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	i = 0;
	do {
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap(array + i, min);
			print_array(array, size);
		}
		i++;
	} while (i < size - 1);
}
