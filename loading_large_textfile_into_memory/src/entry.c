#include "entry.h"

char **load_entry(char *filename, int *len)
{
	FILE *fp = fopen(filename, "r");
	if (!fp) {
		fprintf(stderr, "%s\n", "Error readign file!");
		return NULL;
	}

	/* allocate spaces for list pointing to strings */
	char **entry = NULL;
	int entry_len = 0;

	/* buffer for read line */
	char buff[BUFF_SIZE];

	int i = 0;
	while (fgets(buff, BUFF_SIZE, fp)) {

		if (i == entry_len) {			
			entry_len += ENTRY_CHUNK;
			char **new_entry = realloc(entry, sizeof(char *) * entry_len);
			if (!new_entry) {
				fprintf(stderr, "%s\n", "Memory reallocation fault!");
				exit(1);
			}
			entry = new_entry;
		}


		/* buffer size */
		int slen = strlen(buff);

		/* trim off new line character */
		buff[slen - 1] = '\0';		

		/* allocate  */
		char *str = (char *)malloc(sizeof(char) * (slen));

		/* copy buff into str */
		strcpy(str, buff);

		/* attach str to entry */
		entry[i] = str;

		/* increment i */
		i++;
	}

	*len = i;
	fclose(fp);
	return entry;
}

void print_entry(char **entry, int len)
{
	int i;
	for (i = 0; i < len; ++i) {
		printf("%s\n", entry[i]);
	}

}
