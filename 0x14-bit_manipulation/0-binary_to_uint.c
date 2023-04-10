#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - that convert a binary number to an unsigned int.
 * @b: where b is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if.
 *     where there is one or more chars in the string b that is not 0 or 1
 *     where b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int int_value;
	unsigned int uint_value = 0;
	if (!b)
		return (0);

	for (int_value = 0; b[int_value]; int_value++)
	{
		if (b[int_value] < '0' || b[int_value] > '1')
			return (0);
		uint_value = 2 * uint_value + (b[int_value] - '0');
	}
	return (uint_value);
}

