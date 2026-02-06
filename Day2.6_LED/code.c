#include <lpc21xx.h>

int main()
{
    IO1DIR = 0xFF;     // P1.0 – P1.7 as output 255

    while(1)
    {
        // ---- BLINK ALL LEDs 5 TIMES ----
        for(int i = 0; i < 5; i++)
        {
            IO1CLR = 0xFF;   // All LEDs ON
            delay_ms(100);

            IO1SET = 0xFF;   // All LEDs OFF
            delay_ms(100);
        }

        // ---- LEFT TO RIGHT SHIFT 5 TIMES ----
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                IO1CLR = (1 << j);  // Turn ON LED at position j
                delay_ms(100);

                IO1SET = (1 << j);  // Turn OFF LED at position j
                delay_ms(100);
            }
        }
    }
}

