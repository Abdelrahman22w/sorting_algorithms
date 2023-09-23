#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list
 * @h: A pointer to the head of the doubly-linked list
 * @n1: A pointer to the first node to swap
 * @n2: A pointer to the second node to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	listint_t *n1_prev = (*n1)->prev;
    listint_t *n1_next = (*n1)->next;
    listint_t *n2_prev = n2->prev;
    listint_t *n2_next = n2->next;
	
    if (*n1 == NULL || n2 == NULL || *h == NULL)
        return; /* Check for invalid pointers */

    /* Save the next and previous nodes of n1 and n2 */


    /* Update n1's next and prev pointers */
    (*n1)->prev = n2_prev;
    (*n1)->next = n2_next;

    /* Update n2's next and prev pointers */
    if (n2_prev != NULL)
        n2_prev->next = *n1;
    else
        *h = *n1; /* Update the head if n2 was the head */

    if (n2_next != NULL)
        n2_next->prev = *n1;

    /* Update n2's next and prev pointers */
    n2->prev = n1_prev;
    n2->next = *n1;

    /* Update n1's next node's prev pointer */
    if (n1_next != NULL)
        n1_next->prev = n2;

    /* Update n1's prev node's next pointer */
    if (n1_prev != NULL)
        n1_prev->next = n2;
    else
        *h = n2; /* Update the head if n1 was the head */

    /* Update n1 pointer to its new position */
    *n1 = n2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: This function sorts the list in ascending order
 *              and prints it after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	/**check if it's already sorted list */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			swap_nodes(list, &prev, current);
			print_list((const listint_t *)*list);
		}
	}
}
