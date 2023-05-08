#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * print_elf_header - Prints the ELF header
 * @header: Pointer to the ELF header
 */
void print_elf_header(const unsigned char *header)
{
	unsigned int i;

	printf("ELF Header:\n");
	printf("  Magic:");
	for (i = 0; i < 16; i++)
		printf(" %02x", header[i]);
	printf("\n");
	/* Rest of the fields go here... */
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;
	unsigned char header[16];
	FILE *file;

	if (argc != 2)
	{
		printf("Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	filename = argv[1];
	file = fopen(filename, "rb");
	if (!file)
	{
		printf("Error: Could not open file '%s'\n", filename);
		return (1);
	}

	if (fread(header, sizeof(header), 1, file) != 1)
	{
		printf("Error: Could not read ELF header from file '%s'\n", filename);
		fclose(file);
		return (1);
	}

	print_elf_header(header);

	fclose(file);
	return (0);
}

