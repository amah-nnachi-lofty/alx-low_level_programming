#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a specified index.
 * @n: A decimal number is passed to the function through a pointer.
 * @index: The index position to change starts from 0
 * * Return: returns 1. If there is an error, the function returns -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
        unsigned int ui;

        if (index > 63)
                return (-1);

        ui = 1 << index;
        *n = (*n | ui);

        return (1);
