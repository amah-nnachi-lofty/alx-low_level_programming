#include "main.h"

/**
 * binary_to_uint - to convert a binary number to an unsigned int.
 * @b: This is a pointer to a string chars of 0 and 1.
 *
 * Return: The converted number, or 0 if b is NULL, there is one.
 *         If not true more chars in the string b that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
        int num;
        unsigned int num_val = 0;

        if (!b)
                return (0);

        for (i = 0; b[num]; num++)
        {
                if (b[num] < '0' || b[num] > '1')
                        return (0);
                num_val = 2 * num_val + (b[num] - '0');
        }
        return (num_val);
}
