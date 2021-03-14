#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sizeof_concept(void);
void size_t_concept(void);
void void_ptr_concept(void);
void void_ptr(void *, size_t);
void free_safe(void *);

int main()
{
	sizeof_concept();
	size_t_concept();
	void_ptr_concept();
	return 0;
}

void sizeof_concept(void)
{
	/** 
	 * define siz_t variable to store sizeof other variable (type).
	 * use zd to print size_t variable.
	 **/
	size_t char_size = sizeof(char);
	printf("%s: %zu\n", "sizeof char", char_size);

	size_t short_size = sizeof(short);
	printf("%s: %zu\n", "sizeof short", short_size);

	size_t int_size = sizeof(int);
	printf("%s: %zu\n", "sizeof int", int_size);

	size_t long_size = sizeof(long);
	printf("%s: %zu\n", "sizeof long", long_size);

	size_t float_size = sizeof(float);
	printf("%s: %zu\n", "sizeof float", float_size);

	size_t double_size = sizeof(double);
	printf("%s: %zu\n", "sizeof souble", double_size);

	/** 
	 * using sizeof to allocate memory 
	 * need to include stdlib
	 **/
	char *list = malloc(sizeof(char) * 3);
	if (list == NULL) {
		printf("%s\n", "ERROR! memory allocation");
		return;
	}

	/**
	 * free allocated memory
	 **/
	free(list);
}

void size_t_concept(void)
{
	/**
	 * declare and initialize an char array, 
	 * size of array could be larger than int.
	 * size_t is a type guaranteed to hold any array index.
	 **/
	char sent[] = "Hello, this is just test.";

	/**
	 * size of object may be longer than maximum of integer
	 * therefore we should use size_t for value of size of object
	 * in most compiler size_t is unsigned long
	 **/
	size_t i;
	for (i = 0; i < strlen(sent); ++i) {
		printf("%c ", sent[i]);
	}

	/**
	 * zu for print size_t value
	 **/
	printf("\n%zu\n", strlen(sent));

	/**
	 * sizeof(array) can be used to get real size of array
	 **/
	printf("\n%zu\n", sizeof(sent)/sizeof(sent[0]));
}

/**
 * The purpose of void * is realised when the algorithm doesn't care about the real type of the objects. 
 * A good example is the standard sorting function qsort(), which is declared as:
 **/
void void_ptr_concept(void)
{
	char *holder_1 = NULL;
	int *holder_2 = NULL;
	int *holder_3 = NULL;

	/**
	 * allocating with calloc. 
	 **/
	/* holder = (int *)calloc(10, sizeof(int)); */

	/**
	 * allocating with malloc and initialize with memset.
	 **/
	holder_1 = (char *)malloc(sizeof(int) * 15);
	memset(holder_1, 0, sizeof(char) * 15);

	holder_2 = (int *)malloc(sizeof(int) * 10);
	memset(holder_2, 0, sizeof(int) * 10);

	/**
	 * pass pointer with type char * to function
	 **/
	void_ptr(holder_1, 15);

	/**
	 * pass pointer with type int * to function
	 **/
	void_ptr(holder_2, 10);	


	/**
	 * pass pointer with type char * to function
	 **/
	free_safe(holder_1);

	/**
	 * pass pointer with type int * to function
	 **/
	free_safe(holder_2);	

	/** 
	 * pass pointer with type int * to function 
	 **/
	free_safe(holder_3);	
}

/**
 * This function accept void pointer parameter and do nothing.
 **/
void void_ptr(void *ptr, size_t length)
{
	printf("[Block %zu] %p \n", length, ptr);
}

/**
 * This function accept adress of void pointer parameter and free it.
 **/
void free_safe(void *ptr)
{
	free(ptr);
}
