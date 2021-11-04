/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	Video (demo): 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned array[3][8] = {{0x01, 0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02},
			{0x11, 0x1B, 0x1F, 0x1B, 0x11, 0x04, 0x0A, 0x11},
			{0x04, 0x0E, 0x1F, 0x1B, 0x11, 0x00, 0x04, 0x0E}, 
			} ;
unsigned char i, j = 0x00 ;
unsigned char invert = 0x00 ;
enum States {Start, Begin, Init, Reset, ResetOn, Plus, Minus, PlusOn, MinusOn} state ;
void Tick(){
	switch(state){
		case Start:
			state = Begin ;
			break ;
		case Begin:
			state = Init ;
			break ;
		case Init:
			if((~PINA & 0x01) == 0x01) state = PlusOn ;
			else state = Init ;
			break ;
		case Plus:
			if((~PINA & 0x01) == 0x01) state = Plus ;
                        else state = Init ;
                        break ;
		case PlusOn:
			state = Plus ;
			break ;
		default:
			state = Start ;
			break ;
	}
	switch(state){
		case Start:
			PORTB = 0x00 ;
			break ;
		case Begin:
			PORTB = 0x00 ;
			break ;
		case Init:
			break ;
		case Plus:
			break ;
		case PlusOn:
			if(j < 7) j++ ;
			else{
				if(i < 2) i++ ;
				else i = 0 ;
				j = 0 ;
			}	
                        break ;
		default:
			PORTB = 0x00 ;
			break ;
	}
	PORTB = array[i][j] ;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    /* Insert your solution below */
    DDRA = 0x00 ; PORTA = 0xFF ;
    DDRB = 0xFF ; PORTB = 0x00 ;
    while (1) {
	Tick() ;
    }
    return 1 ;
}
