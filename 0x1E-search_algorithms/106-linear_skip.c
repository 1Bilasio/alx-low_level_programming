#include <stdio.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present in list or if list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);
	current = list;
	while (current->express)
	{
	prev = current;
	current = current->express;
	printf("Value checked at index [%lu] = [%d]\n", current->index,
			current->n);
	if (current->n >= value)
		{
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
				current->index);
		break;
		}
	}
	if (!current->express)
	{
	prev = current;
	while (current->next)
		current = current->next;
	printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
			current->index)
	}
	while (prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
