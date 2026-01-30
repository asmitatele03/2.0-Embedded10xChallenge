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

