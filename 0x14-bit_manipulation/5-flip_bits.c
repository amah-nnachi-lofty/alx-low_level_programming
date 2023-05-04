#include "main.h"

/**
 * flip_bits - function returns the number of bits.
 * need to be flipped to transform one number into another.
 * @n: number one to calculate the bit flips.
 * @m: number two to calculate the bit flips.
 *
 * Return: returns the number of flipped bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int transf;
	int count;

	transf = n ^ m;
	count = 0;

	while (transf)
	{
		count++;
		transf &= (transf - 1);
	}

	return (count);
}
