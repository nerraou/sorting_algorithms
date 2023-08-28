#include "sort.h"


/**
 * _swap - swap elements
 * @val1: val1
 * @val2: val2
 */
void _swap(int *val1, int *val2)
{
	int tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

/**
 * bubble_sort - bubble sort
 * @array: array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
