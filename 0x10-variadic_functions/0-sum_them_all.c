#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of the paramters.
 * @n: The number of paramters passed to function.
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	int sum = 0;
	unsigned int i = 0;

	va_start(ap, n);

	while (i < n)
	{
		sum += va_arg(ap, int);
		i++;
	}

	va_end(ap);

	return (sum);
}
