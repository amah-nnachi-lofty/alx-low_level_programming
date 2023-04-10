#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
        unsigned int n1, p2;
        int lenghts;

        if (b == NULL)
                return (0);

        for (lenghts = 0; b[lenghts]; lenghts++)
        {
                if (b[lenghts] != '0' && b[lenghts] != '1')
                        return (0);
        }

        for (p2 = 1, n1 = 0, lenghts--; lenghts >= 0; lenghts--, p2 *= 2)
        {
                if (b[lenghts] == '1')
                        n1 += p2;
        }

        return (n1);
}
