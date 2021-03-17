/**
 * From Wikipedia, the free encyclopedia
 * ATmega328P in 28-pin narrow dual in-line package (DIP-28N)
 * ATmega328P in 32-pin thin quad flat pack (TQFP-32)
 * The ATmega328 is a single-chip microcontroller created by Atmel
 * in the megaAVR family (later Microchip Technology acquired Atmel in 2016). 
 * It has a modi fied Harvard architecture 8-bit RISC processor.
 **/

#include <stdio.h>

/* Eight bit Micro Controller */
#define PORT_LENGTH 8

typedef unsigned char PORT;
typedef unsigned char POSITION; /* 7 6 5 4 3 2 1 0 */

static inline void bset(PORT *p, POSITION pos) { *p |= (1 << pos); }
static inline void bclear(PORT *p, POSITION pos) { *p &= ~(1 << pos); }
static inline void bflip(PORT *p, POSITION pos) { *p ^= (1 << pos); }
static inline char bget(PORT *p, POSITION pos) { return 1 & (*p >> pos); }

void print_port(PORT *);

int main()
{
	PORT PORT_A;	
	
	PORT_A = 0x00;
	print_port(&PORT_A);

	bset(&PORT_A, 4);
	print_port(&PORT_A);

	bset(&PORT_A, 2);
	print_port(&PORT_A);

	bflip(&PORT_A, 6);
	print_port(&PORT_A);

	bflip(&PORT_A, 4);
	print_port(&PORT_A);

	bflip(&PORT_A, 4);
	print_port(&PORT_A);

	return 0;	
}

void print_port(PORT *p)
{
	printf("[0x%x] ", *p);
	int i;	
	for (i = PORT_LENGTH - 1; i >= 0; --i) {
		printf("%d", bget(p, i));
	}
	printf("\n");
}
