#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint: to convert a binary number to an unsigned int
 * 
 * @b: a binary pointer to a string chars of 0 and 1
 * 
 * Return: the converted number, or 0 if b is NULL, there is one or more chars in the string b that is not 0 or 1
 *
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int name1, raise_power;
int int_len;
	if (b == NULL)
		return (0);

	    for (int_len = 0; b[int_len]; int_len++)
	    {
	if (b[int_len] != '0' && b[int_len] != '1')
			return (0);
	    }

	    for (raise_power = 1, name1 = 0, int_len--; int_len >= 0; int_len--, raise_power *= 2)
	    {
	if (b[int_len] == '1')
			name1 += raise_power;
	    }

	return (name1);
}
