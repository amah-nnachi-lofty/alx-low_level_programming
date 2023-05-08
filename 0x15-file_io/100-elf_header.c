#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

/**
 * print_elf_header - Display the information contained in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header) {
    unsigned int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < sizeof(header->e_ident); i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
    printf("  Type:                              0x%04x\n", header->e_type);
    printf("  Machine:                           0x%04x\n", header->e_machine);
    printf("  Version:                           0x%08x\n", header->e_version);
    printf("  Entry point address:               0x%016lx\n", header->e_entry);
    printf("  Start of program headers:          %lu (bytes into file)\n", header->e_phoff);
    /* Rest of the fields go here... */
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
    const char *filename;
    Elf64_Ehdr header;
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s elf_filename\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    if (fread(&header, sizeof(header), 1, file) != 1) {
        printf("Error: Could not read ELF header from file '%s'\n", filename);
        fclose(file);
        return 1;
    }

    print_elf_header(&header);

    fclose(file);
    return 0;
}

