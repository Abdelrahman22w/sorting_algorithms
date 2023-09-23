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
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
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

int main(void)
{
	int array[] = {5, 1, 4, 2, 8};
	size_t size = sizeof(array) / sizeof(array[0]);

	print_array(array, size);
	bubble_sort(array, size);
	print_array(array, size);

	return 0;
}
