#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

// Create display object (address from your I2C scan!)
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  alpha4.begin(0x70); // Substitute address as needed
  alpha4.writeDisplay();
}

void loop() {
  alpha4.writeDigitAscii(0, 'A');
  alpha4.writeDigitAscii(1, 'b');
  alpha4.writeDigitAscii(2, '1');
  alpha4.writeDigitAscii(3, '2');
  alpha4.writeDisplay();
  delay(1000);
}
