#include <stdlib.h>
#include <stdio.h>

extern int util(int);

void mess ()
{
	printf("%s\n", "message");
}

int main(int argc,
	char* argv[]) {
	printf("Hello, world!\n");
	mess();		
	return util(argc);
}
