#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * print_elf_header - Prints the ELF header information.
 * @header: Pointer to the ELF header array.
 */
void print_elf_header(const unsigned char *header)
{
	unsigned int i;

	printf("ELF Header:\n");
	printf("Magic:  ");
	for (i = 0; i < 16; i++)
		printf("%02x ", header[i]);
	printf("\n");
	printf("Class:  %s\n", header[4] == 1 ? "ELF32" : "ELF64");
	printf("Data:  %s\n", header[5] == 1 ? "2's complement, little-endian"
					  : "2's complement, big-endian");
	printf("Version:  %d (current)\n", header[6]);
	printf("OS/ABI:  ");
	switch (header[7])
	{
		/* OS/ABI cases... */
	}
	printf("ABI Version:  %d\n", header[8]);
	printf("Type:  %d\n", *(uint16_t *)(header + 16));
	printf("Entry point address:  0x%x\n", *(uint32_t *)(header + 24));
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	const char *filename;
	unsigned char header[64];
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

