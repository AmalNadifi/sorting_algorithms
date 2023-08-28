#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list of
 * integers in ascending order using the Insertion Sort Algorithm
 * @list: ThE Pointer to the head of the doubly linked list
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL, *swap_tmp = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	for (current = *list; current;)
	{
		if (current->next && (current->n >  current->next->n))
		{
			temp = current->next;
			for (swap_tmp = temp; swap_tmp->prev;
					swap_tmp = swap_tmp->prev)
				if ((swap_tmp->prev->n) < (swap_tmp->n))
					break;
			if (temp->next && temp->prev)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			else
				temp->prev->next = NULL;
			temp->next = swap_tmp;
			if (swap_tmp->prev)
			{
				swap_tmp->prev->next = temp;
				temp->prev = swap_tmp->prev;
				swap_tmp->prev = temp;
			}
			else
			{
				swap_tmp->prev = temp, temp->prev = NULL;
				*list = temp;
			}
			print_list(*list), current = *list;
			continue;
		} current = current->next;
	}
}
