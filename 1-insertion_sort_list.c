#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list of
 * integers in ascending order using the Insertion Sort Algorithm
 * @list: ThE Pointer to the head of the doubly linked list
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;  /* Sorted part of the list */
	listint_t *unsorted = *list;  /* Unsorted part of the list */
	listint_t *ia = NULL;/* The Insert after variable */

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (unsorted != NULL)
	{
		ia = NULL;
		while (sorted && sorted->n < unsorted->n)
		{
			ia = sorted;
			sorted = sorted->next;
		}
		if (!ia)
		{
			(*list)->prev = unsorted;
			(*list) = unsorted;
			unsorted = unsorted->next;
			(*list)->next = sorted;
			(*list)->prev = NULL;
		}
		else
		{
			ia->next = unsorted;
			unsorted = unsorted->next;
			if (unsorted)
				unsorted->prev = ia;
			ia->next->next = sorted;
			ia->next->prev = ia;
			if (sorted)
				sorted->prev = ia->next;
		}
		/* Printing the list after each swap */
		print_list(*list);
	}
}
