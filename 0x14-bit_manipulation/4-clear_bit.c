#include "main.h"

/**
 * clear_bit - function sets the value of a bit to 0.
 * at a specified index.
 * @n: A pointer of an unsigned long int.
 * @index: index of the bit at a given value.
 *
 * Return: returns a value of 1 or -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int o;

	if (index > 63)
		return (-1);

	o = 1 << index;

	if (*n & o)
		*n ^= o;

	return (1);
}
