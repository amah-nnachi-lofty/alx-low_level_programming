#include "main.h"

/**
 * read_textfile - reads a file and prints the characters to POSIX stdout.
 * @filename: A pointer, an address reference to the file's name.
 * @letters: Actual number of printed letters.
 *
 * Return: If an error, returns 0. Else, print number of letters.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	ssize_t rlen;
        ssize_t	wlen;
	char *buffer;

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);

	if (f == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	rlen = read(f, buffer, letters);
	wlen = write(STDOUT_FILENO, buffer, rlen);

	close(f);
	free(buffer);

	return (wlen);
}
