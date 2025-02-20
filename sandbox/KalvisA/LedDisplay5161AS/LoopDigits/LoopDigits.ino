#include "SevSeg.h"
SevSeg sevseg;

void setup() {
    byte numDigits = 1;
    byte digitPins[] = {};
    //                    A, B, C, D, E, F, G, DP                   
    byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
    bool resistorsOnSegments = true;
  
    byte hardwareConfig = COMMON_CATHODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop() {
    // Array of hexadecimal characters
    char hexChars[] = "0123456789ABCDEF";
    int numChars = sizeof(hexChars) - 1; // Size of the array minus the null terminator
    
    for (int i = 0; i < numChars; i++) {
        char mychars[] = {hexChars[i]};
        sevseg.setChars(mychars);
        
        // Refresh the display continually for about 1 second
        unsigned long startTime = millis();
        while (millis() - startTime < 1000) {
            sevseg.refreshDisplay();
        }
    }
}