#include "main.h"

/**
 * create_file - function to creates a file.
 * @filename: A pointer, an address reference to the file's name.
 * @text_content: The content writed in the filename.
 *
 * Return: If an error, returns -1. Else, return 1.
 */
int create_file(const char *filename, char *text_content)
{
	int f;
	int fname;
	int rwrite;

	if (!filename)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (f == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (fname = 0; text_content[fname]; fname++)
		;

	fname = write(f, text_content, fname);

	if (fname == -1)
		return (-1);

	close(fd);

	return (1);
}