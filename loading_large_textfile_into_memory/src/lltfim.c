#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		fprintf(stderr, "%s\n", "Must supply a filename to read!");
		exit(1);
	}

	/* int s = add_num(5, 7); */
	/* printf("%d\n", s); */

	int length = 0;
	char **words;
	
	words = load_entry(argv[1], &length);
	print_entry(words, length);


	/* clean allocated memory */
	if (words != NULL) {
		int i;
		for (i=0; i < length; ++i) {
			free(* (words + i));
		}
		free(words);
	}
	
	return 0;
}
