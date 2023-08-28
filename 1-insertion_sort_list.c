#include "sort.h"

/**
 * _swap - swap two nodes
 * @node: iterator
 * @list: head
 * Return: current
 */
listint_t *_swap(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev;
	listint_t *curr = node;

	prev->next = curr->next;
	if (curr->next)
		curr->next->prev = prev;
	curr->next = prev;
	curr->prev = prev->prev;
	prev->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}

/**
 * insertion_sort_list - dlinked list insertation sort
 * @list: head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *it;
	listint_t *r_it;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	it = *list;
	while (it != NULL)
	{
		r_it = it;
		it = it->next;
		while (r_it != NULL)
		{
			if (r_it->prev != NULL && r_it->n < r_it->prev->n)
			{
				it = _swap(r_it, list);
				print_list(*list);
			}
			r_it = r_it->prev;
		}
	}
}
