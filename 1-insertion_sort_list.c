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
	listint_t *current = NULL, *temp = NULL;/*Current &temp node toinsert*/
    
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (unsorted != NULL)
	{
		current = unsorted;
		unsorted = unsorted->next;
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;
			if (temp->next != NULL)
			{
				temp->next->prev = current;
				print_list(*list);
			}

			temp->next = current;
		}
	}
	*list = sorted; /* Update the head of the list */
}
