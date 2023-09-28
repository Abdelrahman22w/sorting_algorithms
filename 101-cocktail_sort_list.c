#include "sort.h"
#include <stdio.h>

/**
 * swap_n - swaps two nodes in a doubly linked list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap_n(listint_t **list, listint_t *node)
{
	listint_t *prev_node, *next_node;

	if (node == NULL || node->next == NULL)
		return;

	prev_node = node->prev;
	next_node = node->next;

	if (prev_node != NULL)
		prev_node->next = next_node;
	else
		*list = next_node;

	next_node->prev = prev_node;
	node->prev = next_node;
	node->next = next_node->next;
	next_node->next = node;

	if (node->next != NULL)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;

		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap_n(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;

		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_n(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
