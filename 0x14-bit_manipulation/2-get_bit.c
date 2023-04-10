#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index.
 * @index: index of n to get bit from.
 * @n: unsigned number long int bit
 * @index: The index to get the value at - indices start at 0.
 * Return: bit at index if error occur - 1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	return ((n >> index) & 1);
}
