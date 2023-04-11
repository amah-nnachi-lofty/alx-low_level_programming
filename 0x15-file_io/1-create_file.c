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
	int file;
        int nlet, 
	int wr;

	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlet = 0; text_content[nlet]; nlet++);

	wr = write(file, text_content, nlet);

	if (wr == -1)
		return (-1);

	close(file);

	return (1);
}
