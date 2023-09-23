#include "sort.h"
#include <stdbool.h>

/**
* swap - swap the values of integer
* @a: first int
* @b: second int
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
* bubble_sort - sort an array in ascending order by bubble algo
* @array: the array to be sorted
* @size: the size of the array
* Return: the sorted array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	do {

		swapped = false;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				swapped = true;
				print_array(array, size);
			}
		}

		len--;
	} while (swapped);
}
