#include "main.h"

/**
 * read_textfile - reads a file and prints the characters to POSIX stdout.
 * @filename: A pointer, an address reference to the file's name.
 * @letters: Actual number of printed letters.
 * Description: Opens a file using the given filename, reads up to
 * `letters` number of characters from the file into a dynamically allocated
 * buffer, writes the contents of the buffer to the standard output file
 * descriptor (STDOUT_FILENO), and then closes the file and frees the memory
 * allocated for the buffer. It the number of bytes written to
 * the standard output, or 0 if there's an error.
 *
 * Return: If an error, returns 0. Else, print number of letters to stdout.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t rlen, wlen;
	char *buffer;

	if (!filename)
		return (0);

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	rlen = read(file_descriptor, buffer, letters);
	wlen = write(STDOUT_FILENO, buffer, rlen);

	close(file_descriptor);

	free(buffer);

	return (wlen);
}
