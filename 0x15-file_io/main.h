#ifndef MAIN_H
#define MAIN_H

/*libraries*/
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*Prototypes & functions*/
void print_elf_header(const unsigned char *header);
void close_file(int file_descriptor);
char *create_buffer(char *file_name);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif

