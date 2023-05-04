#include "main.h"

/**
 * get_endianness - checks the endianness of a system.
 *
 * Return: big endian returns 0, while the little returns 1.
 *
 */
int get_endianness(void)
{
	int n;

	n = 1;
	if (*(char *)&n == 1)
		return (1);
	else
		return (0);
}
