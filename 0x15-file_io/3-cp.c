#include "main.h"

char *create_buffer(char *file_name);
void close_file(int file_descriptor);

/**
 * create_buffer - 1024 bytes is allocated to buffer.
 * @file_name: Name given to file where buffer stores char.
 *
 * Return: The new allocated buffer pointer.
 */
char *create_buffer(char *file_name)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file_name);
		exit(99);
	}
	else
	{
		return (buffer);
	}
}

/**
 * close_file - To close the file descriptors.
 * @file_descriptor: File descriptors.
 */
void close_file(int file_descriptor)
{
	int c;

	c = close(file_descriptor);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
	else
	{
		return;
	}
}

/**
 * main - To copy contents of a file to another file.
 * @argc: Number of command arguments.
 * @argv: Array of pointers.
 *
 * Return: 0 on success.
 *
 * Description: When the argument count is incorrect, then exit code 97.
 *              When file_from does not exisis nil or not read, exit code 98.
 *              When files fails to create or written to, then exit code 99.
 *              When file_to or file_from fails to close, then exit code 100.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, read_bytes, written_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	else
	{
		buffer = create_buffer(argv[2]);
		from_fd = open(argv[1], O_RDONLY);

		if (from_fd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		else
		{
			read_bytes = read(from_fd, buffer, 1024);
			to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

			if (to_fd == -1)
			{
				dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
				free(buffer);
				exit(99);
			}
			else
			{
				do {
					written_bytes = write(to_fd, buffer, read_bytes);

					if (written_bytes == -1)
					{
						dprintf(STDERR_FILENO,
							"Error: Can't write to %s\n", argv[2]);
						free(buffer);
						exit(99);
					}

					read_bytes = read(from_fd, buffer, 1024);

				} while (read_bytes > 0);

				close_file(from_fd);
				close_file(to_fd);
				free(buffer);

				return (0);
			}
		}
	}
}
