#include <LedControl.h>

// DIN pin 11, CLK pin 13, CS pin 10, number of devices is 1
LedControl lc=LedControl(11,13,10,1);

void setup() {
    lc.shutdown(0,false);    // Wake up MAX7219
    lc.setIntensity(0,1);    // Set brightness (0--15)
    lc.clearDisplay(0);      // Clear display
}

void loop() {
    for (int row = 0; row < 8; row++) {
        byte pattern = 0b10101010; // Binary: 10101010
        // Alternate rows to create a chessboard
        if (row % 2 == 1) pattern = ~pattern;
        lc.setRow(0, row, pattern);
    }
    // Hold steady
    while (true);
}