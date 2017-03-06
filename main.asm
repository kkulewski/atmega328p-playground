.nolist 
.include "m328pdef.inc" 
.list 

.cseg 
.org 0 

ldi R16, 0b00000001
out DDRB, R16 
out PORTB, R16 