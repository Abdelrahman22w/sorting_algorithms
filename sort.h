#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*function's prototypes*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int low, int high);
void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

#endif
