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
 * partition - partition
 * @arr: array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: pivot
 */
int partition(int *arr, int start, int end, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = arr[end];
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[i] != arr[j])
			{
				_swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (arr[i + 1] != arr[end])
	{
		_swap(&arr[i + 1], &arr[end]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - quick sort recursive
 * @array: array
 * @size: array size
 * @start: starting index
 * @end: ending index
 */
void quick_sort_recursive(int *array, size_t size, int start, int end)
{
	int pi;

	if (start >= end || start < 0)
		return;
	pi = partition(array, start, end, size);
	quick_sort_recursive(array, size, start, pi - 1);
	quick_sort_recursive(array, size, pi + 1, end);
}

/**
 * quick_sort - quick sort
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursive(array, size, 0, size - 1);
}
