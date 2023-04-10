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
	char *buff;
	ssize_t rlen;
       	ssize_t wlen;

	if (filename == NULL || letters == 0)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buff = malloc(sizeof(char) * (letters));
	if (buff == NULL)
		return (0);
	rlen = read(f, buff, letters);
	if (rlen == -1)
		return (0);
	wlen = write(STDOUT_FILENO, buff, rlen);
	free(buff);
	close(f);
	if (rlen != wlen)
		return (0);
	return (wlen);
}
