#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

// IF PC0 is driven HIGH -> PB0 led will blink
// IF PC0 is driven LOW  -> PB0 led wont blink
// IF PC0 is floating -> PB0 led will or will not blink (tri-state)
int main(void)
{
	// PIN MODE: 1 - OUT, 0 - IN
	// last bit = Px0
	// PB0 = output
	DDRB = 0b00000001;
	// PCx = input
	DDRC = 0b00000000;
	// turn off pull-up resistors on PCx
	PORTC = 0b00000000;
	int a = 1;
	
    while (1) 
    {
		
		// set PB0 high
		PORTB = 0b00000001;
		_delay_ms(100);
		// read PCx and only select PC0, then check if PC0 != 0
		if((PINC & 00000001) != 0)
		{
			// set PB0 low
			PORTB = 0b00000000;
		}
		_delay_ms(100);
		
    }
}

