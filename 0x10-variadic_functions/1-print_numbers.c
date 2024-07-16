#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Prints numbers, with a new line.
 * @separator: Inbetween the numbers this is the string to be printed .
 * @n: The number of integers passed to the function.
 * @...: An unknown number of variables to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int index = 0;

	va_start(nums, n);

	while (index < n)

	{
		printf("%d", va_arg(nums, int));

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
		index++;
	}
	printf("\n");

	va_end(nums);
}
