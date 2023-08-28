#include "sort.h"

/**
 * bubble_sort - This function sorts an array of integer numbers
 * in ascending order using the Bubble Sort Algorithm
 * @array: the array of integers to sort
 * @size: The size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int s; /* the flag to track swaps occurences */

	/* Start checking for the edge cases */
	if (array == NULL || size < 2)
		return;

	/* Iteration through the entire array */
	for (x = 0; x < size - 1; x++)
	{
		s = 0;
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				s = array[y];
				array[y] = array[y + 1];
				array[y + 1] = s;
				print_array(array, size);
			}
		}
	}
}
