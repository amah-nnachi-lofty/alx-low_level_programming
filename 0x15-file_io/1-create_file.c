#include "main.h"

/**
 * create_file - function to create a file.
 * @filename: A pointer to the filename.
 * @text_content: The content to write to the file.
 *
 * Return: If an error occurs, returns -1. Otherwise, returns 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, length = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* If text_content is not NULL, calculate its length */
	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	/* Open the file for read-write access and create it if it does not exist */
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	/* Write the content to the file if it is not NULL */
	if (text_content != NULL)
	{
		write_result = write(file_descriptor, text_content, length);
		if (write_result == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}
