#include <LedControl.h>

// DIN pin 11, CLK pin 13, CS pin 10, number of devices is 1
LedControl lc=LedControl(11,13,10,1);
int x = 0; 
int y = 0; 

void setup() {
    lc.shutdown(0,false);    // Wake up MAX7219
    lc.setIntensity(0,1);    // Set brightness (0--15)
    lc.clearDisplay(0);      // Clear display
}


void loop() {
    for (int row = 0; row < 8; row++) {
        byte pattern = 0b00000000; // Binary: 10101010
        // Alternate rows to create a chessboard
        // if (row % 2 == 1) pattern = ~pattern;
        if (row == y) {
            pattern = pattern ^ (1 << x);
        }
        lc.setRow(0, row, pattern);
    }
    // Hold steady
    delay(1000);
    x = (x + 3) % 8;
    y = (y + 5) % 8;

}

