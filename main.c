#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

// IF PC0 is driven HIGH -> PB0 led will turn on
// IF PC0 is driven LOW  -> PB0 led will turn off
// IF PC0 is "floating"  -> PB0 led will turn on or off randomly (PC0 tri-state)
int main(void)
{
	// PIN MODE: 1 - OUT, 0 - IN
	// PB0 =  as output
	DDRB = 0b00000001;
	// PCx = as input
	DDRC = 0b00000000;
	// turn off pull-up resistors on PCx
	PORTC = 0b00000000;
	
    while (1) 
    {
		// if PC0 == HIGH
		if((PINC & 0b00000001) == 1)
		{
			// set PB0 HIGH
			PORTB = 0b00000001;
		}
		else
		{
			// set PB0 LOW
			PORTB = 0b00000000;
		}
		// wait 100 miliseconds
		_delay_ms(100);		
    }
}

