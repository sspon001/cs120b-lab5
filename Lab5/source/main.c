/*	Author: sspon001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00 ; PORTA = 0xFF ;
	DDRC = 0xFF ; PORTC = 0x00 ;
	unsigned char a, c ;
    while (1) {
	a = PINA ;
	c = 0x00 ;
	if (((a & 0x0D) == 0x0D) || ((a & 0x0E) == 0x0E) || ((a & 0x0F) == 0x0F)) {
                c = 0x3F ;
        }
	else if (((a & 0x0A) == 0x0A) || ((a & 0x0B) == 0x0B) || ((a & 0x0C) == 0x0C)) {
                c = 0x3E ;
        }
	else if (((a & 0x07) == 0x07) || ((a & 0x08) == 0x08) || ((a & 0x09) == 0x09)) {
                c = 0x3C ;
        }
	else if (((a & 0x05) == 0x05) || ((a & 0x06) == 0x06)) {
                c = 0x38 ;
        }
	else if (((a & 0x03) == 0x03) || ((a & 0x04) == 0x04)) {
                c = 0x70 ;
        }
	else if (((a & 0x01) == 0x01) || ((a & 0x02) == 0x02)) {
		c = 0x60 ;
	}
	else {
		c = 0x40 ;
	}
	PORTC = c ;
    }
    return 1;
}
