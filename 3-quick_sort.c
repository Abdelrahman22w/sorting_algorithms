#include "sort.h"
#include "swap.c"
/**
 * lomuto_sort - Implement the quicksort algorithm using Lomuto partition.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
    int pivot, i, j;

    if (low < high)
    {
        pivot = array[high];
        i = low - 1;

        for (j = low; j <= high - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }

        swap(&array[i + 1], &array[high]);
        print_array(array, size);

        lomuto_sort(array, size, low, i);
        lomuto_sort(array, size, i + 2, high);
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
