#include <lpc21xx.h>
#include "header.h"
#define S "vector"   // micro  

int main() 
{
    int i, j, k;

    lcd_init();
    lcd_cmd(0x01);     // Clear display

    while(1)
    {
        j = strlen(S);
        k = 1;

        for(i = 0; i < 16; i++)
        {
            lcd_cmd(0x80 + i);   // Move cursor
            lcd_string(S);       // Print string

            delay_ms(500);
            lcd_cmd(0x01);       // Clear display

            k++;
            if(k == j)
                k = 0;

            lcd_string(S + k);   // Shifted display
        }
    }
}

