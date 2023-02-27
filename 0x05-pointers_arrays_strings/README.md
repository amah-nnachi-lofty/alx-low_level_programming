0x05. C - Pointers, arrays and strings


# Task 0"
Create the following files

- main.h

- holberton.h
int _putchar(char c);
void reset_to_98(int *n);
void swap_int(int *a, int *b);
int _strlen(char *s);
void _puts(char *str);
void print_rev(char *s);
void rev_string(char *s);
void puts2(char *str);
void puts_half(char *str);
void print_array(int *a, int n);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);

- 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
  int n;

  n = 402;
  printf("n=%d\n", n);
  reset_to_98(&n);
  printf("n=%d\n", n);
  return (0);
}

- 0-reset_to_98.c
#include "holberton.h"
/**
 * reset_to_98 - check the code for Holberton School students.
 * @n: declaration of n and paramters for the function reset_to_98
 * Return: Always 0.
 */
void reset_to_98(int *n)
{
	*n = 98;
}
