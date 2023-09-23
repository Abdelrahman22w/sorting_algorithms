#include "sort.h"

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
