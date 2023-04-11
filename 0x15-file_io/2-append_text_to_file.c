#include "main.h"

/**
 * append_text_to_file - Text is appended at the end of a file.
 * @filename: A pointer, an address reference to the file's name.
 * @text_content: The content writed in the filename.
 * Return: If an error, returns -1. Else, return 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ft, status, i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);

	ft = open(filename, O_APPEND | O_WRONLY);
	if (ft == -1)
		return (-1);

	for (i = 0; text_content[i] != '\0'; i++)
		;
	status = write(ft, text_content, i);
	if (status == -1)
		return (-1);

	close(ft);
	return (1);
}
