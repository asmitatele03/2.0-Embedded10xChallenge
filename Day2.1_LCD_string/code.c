#include <lpc21xx.h>
#include "header.h"

int main()
{
    int i;
    lcd_init();

    while(1)
    {
        for(i = 0; i < 16; i++)  //first row of lcd
        {
            lcd_cmd(0x80 + i);
            lcd_string("good afternoon");
            delay_ms(200);
            lcd_cmd(0x01);
        }
    }
}

