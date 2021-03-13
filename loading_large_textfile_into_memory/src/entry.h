#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024
#define ENTRY_CHUNK 100

char **load_entry(char *, int *);
void print_entry(char **, int);

