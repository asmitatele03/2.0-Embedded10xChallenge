void lcd_cgram()
{
    lcd_cmd(0x40);       // Set CGRAM address 0 (page 0)

    unsigned char a[8] = {0x00, 0x0A, 0x0A, 0x00, 0x00, 0x0E, 0x11, 0x00};  // address locations

    for(int i = 0; i < 8; i++)
    {
        lcd_data(a[i]);  // Write each row to CGRAM
    }
}

