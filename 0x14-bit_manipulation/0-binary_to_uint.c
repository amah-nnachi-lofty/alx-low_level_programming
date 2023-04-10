#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
        int n;
        unsigned int num_val = 0;

        if (!b)
                return (0);

        for (n = 0; b[n]; n++)
        {
                if (b[n] < '0' || b[n] > '1')
                        return (0);
                num_val = 2 * num_val + (b[n] - '0');
        }
        return (num_val);
}
