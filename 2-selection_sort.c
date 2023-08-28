#include "sort.h"

/**
 * selection_sort - ThiS function sorts an array of integers in ascending order
 * using the Selection Sort Algorithm
 * @array: The pointer to the array of integers
 * @size: The array size
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, idx_min;
	int tmp, sf; /* sf is for the swap flag */

	if (size <= 1)
		return;

	for (x = 0; x < size - 1; x++)
	{
		idx_min = x;
		sf = 0; /* Initialize the flag for each iteration */

		/* Find index of minimum element in remaining unsorted array */
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[idx_min])
			{
				idx_min = y;
				sf = 1; /*Set flag if found smaller element*/
			}
		}

		/* Swap the found minimum element with the first element */
		if (sf == 1)
		{
			tmp = array[idx_min];
			array[idx_min] = array[x];
			array[x] = tmp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}

