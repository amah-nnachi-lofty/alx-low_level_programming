#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: The base i.e the number to be raised.
 * @y: The power or exponents.
 *
 * Return: On success 1.
 * Return: The value of x raised to the power of y.
 * Base case  -> if y less thN 0.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
