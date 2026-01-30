#include<lpc21xx.h>
#include"header.h"
#define sw !((IOPIN0>>14)&1)

int main()
{
    int c = 0;
    lcd_init();

    while(1)
    {
        lcd_cmd(0x80);
        lcd_data((c/10)+48);
        lcd_data((c%10)+48);
        delay_ms(200);
        lcd_cmd(0x01);

        if(sw == 0)
        {
            while(sw == 0);
            c++;

            if(c >= 10)
                c = 0;
        }
    }
}


#include <lpc21xx.h>
#include "header.h"
#define S "vector"   // macro 

int main() 
{
    int i, j, k;  // variable dectaration

    lcd_init();
    lcd_cmd(0x01);     // Clear display

    while(1)
    {
        j = strlen(S);      // string length function
        k = 1;

        for(i = 0; i < 16; i++)   // for loop for first row
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



