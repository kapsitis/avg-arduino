#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  // Initialize the alpha display
  alpha4.begin(0x70); // The I2C address of the display
}

void loop() {
  // Display "1111"
  alpha4.writeDigitAscii(0, '1');
  alpha4.writeDigitAscii(1, '1');
  alpha4.writeDigitAscii(2, '1');
  alpha4.writeDigitAscii(3, '1');
  alpha4.writeDisplay();

  delay(1000);

  // Display "2222"
  alpha4.writeDigitAscii(0, '2');
  alpha4.writeDigitAscii(1, '2');
  alpha4.writeDigitAscii(2, '2');
  alpha4.writeDigitAscii(3, '2');
  alpha4.writeDisplay();

  delay(1000);
}