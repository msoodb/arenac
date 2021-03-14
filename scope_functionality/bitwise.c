#include <stdio.h>

/* Eight bit Micro Controller */
#define PORT_LENGTH 8

typedef unsigned char PORT;
typedef char POSITION; /* 7 6 5 4 3 2 1 0 */

void set_bit(PORT *, POSITION);
void clear_bit(PORT *, POSITION);
void flip_bit(PORT *, POSITION);
char get_bit(PORT *, POSITION);
void print_port(PORT *);	

int main()
{
	PORT PORT_A;	
	
	PORT_A = 0x00;
	print_port(&PORT_A);

	set_bit(&PORT_A, 4);
	print_port(&PORT_A);

	set_bit(&PORT_A, 2);
	print_port(&PORT_A);

	flip_bit(&PORT_A, 6);
	print_port(&PORT_A);

	flip_bit(&PORT_A, 4);
	print_port(&PORT_A);

	flip_bit(&PORT_A, 4);
	print_port(&PORT_A);

	return 0;	
}


/**
 * set bit on POSITION pos in PORT reference p 
 */
void set_bit(PORT *p, POSITION pos)
{
	*p |= (1 << pos);
}

/**
 * clear bit on POSITION pos in PORT reference p 
 */
void clear_bit(PORT *p, POSITION pos)
{
	*p &= ~(1 << pos);
}

/**
 * flip bit on POSITION pos in PORT reference p 
 */
void flip_bit(PORT *p, POSITION pos)
{
	*p ^= (1 << pos);
}

/**
 * return bit on POSITION pos in PORT reference p 
 */
char get_bit(PORT *p, POSITION pos)
{
	return 1 & (*p >> pos);
}

/**
 * print PORT p, bit by bit
 **/
void print_port(PORT *p)
{
	printf("[0x%x] ", *p);
	int i;	
	for (i = PORT_LENGTH - 1; i >= 0; --i) {
		printf("%d", get_bit(p, i));
	}
	printf("\n");
}


