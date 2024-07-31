#include "search_algos.h"
/**
 * advanced_binary_recursive - Recursively search for an integer
 * @array: Pointer to the first element of the array
 * @low: starting index
 * @high: ending index
 * @value: Value to search for
 * Return: index of the first occurence
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (low <= high)
	{
		mid = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= high; ++i)
		{
			if (i > low)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
		if (array[mid] == value)
		{
			if (mid == low || array[mid - 1] != value)
				return (mid);
			else
				return advanced_binary_recursive(array, low,
						mid, value);
		}
		else if (array[mid] < value)
			return advanced_binary_recursive(array, mid + 1,
					high, value);
		else
			return advanced_binary_recursive(array, low, mid + 1,
					value);
	}
	return (-1);
}
/**
 * advanced_binary - Searches for a value in sorted array
 * @array: Pointer to the first element of array to search for
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
