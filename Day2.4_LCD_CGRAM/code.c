#include <LPC214x.h>
#include "header.h"

int main()
{
    lcd_init();      // Initialize LCD
    lcd_cgram();     // Load custom character pattern into CGRAM
    lcd_cmd(0x82);   // Place cursor at specific DDRAM address
    lcd_data(1);     // Display custom character stored at CGRAM location 1 (page 1)
}

