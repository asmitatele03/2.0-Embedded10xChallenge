#include <lpc21xx.h>
#include "header.h"

#define LED 255  

int main()
{
    int i;

    IODIR0 = LED;   // macro
    IOSET0 = LED;   // macro
    delay_ms(20);

    while(1)
    {
        for(i = 0; i < 8; i = i + 2)
        {
            if((i == 0) || (i == 2))    // Based on your image logic
            {
                IOCLR0 = 1 << i;       // Turn LED ON
                delay_ms(20);
                IOSET0 = 1 << i;       // Turn LED OFF
                delay_ms(20);
            }
        }

        if(i == 6)
            i = i - 1;
    }
}

