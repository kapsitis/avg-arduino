#include <Wire.h>

#define I2C_ADDR 0x70   // replace this with the address you found!

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // System setup (as per HT16K33 datasheet)
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x21); // 0x20 | 1: turn on oscillator
  Wire.endTransmission();

  // Display on, no blinking
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x81); // 0x80 | Display on | 0x01: no blink
  Wire.endTransmission();

  // Set brightness (15 max)
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0xEF); // 0xE0 | 0x0F: full brightness
  Wire.endTransmission();

  // Turn on *all* segments for all positions (4 digits × 16 bits)
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00); // Start at address 0

  // For each digit (4 digits, 2 bytes (LOW, HIGH) for each)
  for (uint8_t i = 0; i < 4; i++) {
    Wire.write(0xFF); // lower 8-bits (segments a-g, dp, etc.)
    Wire.write(0xFF); // upper 8-bits (additional segments)
  }
  Wire.endTransmission();
}

void loop() {}