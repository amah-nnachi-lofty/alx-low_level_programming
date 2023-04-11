#include <main.h>

/**
 * create_file - function to creates a file.
 * @filename: A pointer, an address reference to the file's name.
 * @text_content: The content writed in the filename.
 *
 * Return: If an error, returns -1. Else, return 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file, rstatus, i;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		rstatus = write(file, text_content, i);
		if (rstatus == -1)
			return (-1);
	}

	close(file);
	return (1);
}
