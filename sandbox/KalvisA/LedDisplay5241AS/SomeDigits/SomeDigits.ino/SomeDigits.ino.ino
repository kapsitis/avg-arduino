#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>


// Create an object for the 14-segment display
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  // Initialize the display
  alpha4.begin(0x70); // Default I2C address for HT16K33 devices
}

void loop() {
  // Display numbers 0 to 3 on the 4-character 14-segment display
  alpha4.writeDigitAscii(0, '0');
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '2');
  alpha4.writeDigitAscii(3, '3');
  alpha4.writeDisplay();
  delay(1000);

  // Display characters on the 4-character 14-segment display
  alpha4.writeDigitAscii(0, 'A');
  alpha4.writeDigitAscii(1, 'b');
  alpha4.writeDigitAscii(2, 'C');
  alpha4.writeDigitAscii(3, 'd');
  alpha4.writeDisplay();
  delay(1000);

  // Additional sequences or patterns can be added similarly
}