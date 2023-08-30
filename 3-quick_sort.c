#include "sort.h"

/**
 * swap_int - This function swaps two integers
 * @x: the first int
 * @y: the second int
 */
void swap_int(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * pivotize - THis function is sorting an array using Pivot
 * @arr: The array of int
 * @begin: ThE first array
 * @finish: The final array
 * @size: The array size
 * Return: ctr1 + 1
 */
size_t pivotize(int *arr, size_t begin, size_t finish, size_t size)
{
	size_t ctr1, ctr2;
	int pivot = arr[finish];

	ctr1 = begin - 1;
	for (ctr2 = begin; ctr2 < finish; ctr2++)
	{
		if (arr[ctr2] < pivot)
		{
			ctr1++;
			if (ctr1 != ctr2)
			{
				swap_int(&arr[ctr1], &arr[ctr2]);
				print_array(arr, size);
			}
		}
	}
	if (pivot < arr[ctr1 + 1])
	{
		swap_int(&arr[ctr1 + 1], &arr[finish]);
		print_array(arr, size);
	}
	return (ctr1 + 1);
}

/**
 * cqsort - ThIs function is sorting recursively an array using lomuto scheme
 * @a: the array to sort
 * @l: the lowest int in the array
 * @h: the highest int in the array
 * @s: the array size
 * Return: void
 */
void cqsort(int *a, int l, int h, size_t s)
{
	int pi; /* Pivot index */

	if (l < h) /* Base case: low index is less than high index */
	{
		pi = pivotize(a, l, h, s); /* Get the pivot index through pivotize */
		cqsort(a, l, pi - 1, s); /* Recursively sort the left partition */
		cqsort(a, pi + 1, h, s); /* Recursively sort the right partition */
	}
}

/**
 * quick_sort - ThIs function is using Quick Sort algorithm using
 * the lomuto scheme
 * @array: The array to sort
 * @size: the array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	cqsort(array, (size_t)0, size - 1, size);
}
