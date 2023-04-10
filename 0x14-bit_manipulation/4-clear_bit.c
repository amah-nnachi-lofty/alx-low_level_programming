#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a specified index. 
 * * @n: a pointer to a decimal number that needs to be changed as an argument.
 * @index: The index position to change starts at a given value.
 * Return: returns a value of 1. However, if an error occurs, it returns -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int x;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & x)
		*n ^= x;

	return (1);
}
