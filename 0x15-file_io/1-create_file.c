#include "main.h"

/**
 * create_file - function to creates a file.
 * @filename: A pointer, an address reference to the filename.
 * @text_content: The content writed in the filename.
 *
 * Return: If an error, returns -1. Else, return 1.
 */
int create_file(const char *filename, char *text_content)
{
	int m, w, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	m = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(m, text_content, l);

	if (m == -1 || w == -1)
		return (-1);

	close(m);

	return (1);
}
