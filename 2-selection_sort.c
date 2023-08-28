#include "sort.h"

/**
 * _swap - swap elements
 * @val1: value 1
 * @val2: value 2
 */
void _swap(int *val1, int *val2)
{
	int tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

/**
 * selection_sort - selection sort
 * @array: array
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t index_min;
	size_t i;
	size_t j;

	if (size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_min])
				index_min = j;
		}
		if (index_min != i)
		{
			_swap(&array[index_min], &array[i]);
			print_array(array, size);
		}
	}
}
