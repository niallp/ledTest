/* Blink LED example */
/* for MSP430 launchpad board */

#include <msp430g2231.h>

/** Delay function. **/
void delay(unsigned int d) {
  int i;
  for (i = 0; i<d; i++) {
        nop();
  }
}

int main(void) {
	unsigned char p1reg=0;

  WDTCTL = WDTPW | WDTHOLD;
  P1DIR = 0xF7;
  P1OUT = 0x08;
  P1REN = 0x08;

  for (;;) {
    P1OUT = 0x08;
    delay(0x8fff);
    p1reg = 0x09;
    if (P1IN & 0x08)
	    p1reg |= 0x40;
    P1OUT = p1reg;
    delay(0x8fff);
  }
  return 0;
}

