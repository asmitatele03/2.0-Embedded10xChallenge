#include <lpc21xx.h>
#include"header.h"

#define SW (1<<14)

int main()
{
    unsigned int led = 1;
    int direction = 1;      
    unsigned char last = 1;

    IO0DIR |= 0xFF;             
    IO0DIR &= ~SW;          

    while(1)
    {
        /* -------- SWITCH EDGE DETECTION -------- */
        if(!(IO0PIN & SW) && last)
        {
            direction = -direction;  
            delay_ms(10);            // debounce 10ms
        }
        last = (IO0PIN & SW);

        /* -------- LED OUTPUT -------- */
        IO0CLR = 0xFF;
        IO0SET = led;
        
        delay_ms(10);    

        /* -------- SHIFT LOGIC -------- */
        if(direction == 1)
        {
            led <<= 1;
            if(led > 0x80)
                led = 0x01;
        }
        else
        {
            led >>= 1;
            if(led < 0x01)
                led = 0x80;
        }
    }
}

