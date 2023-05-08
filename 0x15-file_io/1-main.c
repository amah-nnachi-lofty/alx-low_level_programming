#include "main.h"

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: An array of strings containing the command-line arguments
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        /* Print an error message with the correct usage of the program */
        dprintf(2, "Usage: %s filename text\n", av[0]);

        /* Exit the program with a non-zero status indicating an error */
        exit(1);
    }

    /* Call the create_file function with the given command line arguments */
    res = create_file(av[1], av[2]);

    /* Print the result of the create_file function */
    printf("-> %i)\n", res);

    /* Return 0 to indicate successful execution of the program */
    return (0);
}

