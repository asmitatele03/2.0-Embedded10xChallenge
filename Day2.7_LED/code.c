#include <lpc21xx.h>

void delay() {
    for (unsigned int i = 0; i < 300000; i++);   // Simple delay
}

int main() {

    IODIR0 = 0xFF << 16;   // Configure LED pins P0.16–P0.23 as output

    while (1) {

        // 1) CENTER ? OUTWARD blinking
        for (int d = 0; d < 4; d++) {
            IOCLR0 = 0xFF << 16;                 // Clear all LEDs
            IOSET0 = (1 << (19 - d)) | (1 << (20 + d));
            delay();
        }

        // 2) OUTWARD ? CENTER blinking
        for (int d = 3; d >= 0; d--) {
            IOCLR0 = 0xFF << 16;
            IOSET0 = (1 << (19 - d)) | (1 << (20 + d));
            delay();
        }

        // 3) ALTERNATE LEDs blink (10101010 ? 01010101)
        for (int i = 0; i < 4; i++) {
            IOCLR0 = 0xFF << 16;
            IOSET0 = 0xAA << 16;     // 10101010
            delay();

            IOCLR0 = 0xFF << 16;
            IOSET0 = 0x55 << 16;     // 01010101
            delay();
        }

        // 4) FULL BLINK (all ON ? all OFF)
        for (int i = 0; i < 3; i++) {
            IOSET0 = 0xFF << 16;
            delay();
            IOCLR0 = 0xFF << 16;
            delay();
        }
    }
}

