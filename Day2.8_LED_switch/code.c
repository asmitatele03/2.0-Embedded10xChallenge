#include <lpc21xx.h>

void delay(int d) 
{ 
for (volatile int i = 0; i < d; i++); 
}

int main() {
    IODIR0 |= (1<<17);
    IODIR0 &= ~(1<<14);

    int mode = 0;
    int speed[] = {900000, 500000, 150000};

    while (1) {
        if (!(IOPIN0 & (1<<14))) 
        {
        mode = (mode + 1) % 3; 
        delay(300000); 
        }

        IOSET0 = (1<<17); 
        delay(speed[mode]);
        IOCLR0 = (1<<17); 
        delay(speed[mode]);
    }
}

