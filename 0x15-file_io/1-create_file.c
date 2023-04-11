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
	int fi;
	int flet;
	int rw;

	if (!filename)
		return (-1);

	fi = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fi == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (flet = 0; text_content[flet]; flet++);

	rw = write(fi, text_content, flet);

	if (rw == -1)
		return (-1);

	close(fi);

	return (1);
}
