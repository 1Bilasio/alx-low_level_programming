#include "search_algos.h"
/**
 * jump_list - Searches for a value in a sorted list of integers
 * @list: Pointer to the head of the list
 * @size: number of nodes in the list
 * @value: Value to search for
 * Return: Pointer to the first node with value
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, i;
	listint_t *current, *prev;

	if (list == NULL)
		return (NULL);
	current = list;
	prev = NULL;
	step = sqrt(size);
	while (current && current->n < value)
	{
		prev = current;
		for (i = 0; current->next && i < step; i++)
			current = current->next;
		printf("Value checked at index [%lu] = [%d]\n", current->index,
			       current->n);
	}
	printf("Value found between [%lu] and [%lu]\n", prev->index, current->
		index);
	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index,
				prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
