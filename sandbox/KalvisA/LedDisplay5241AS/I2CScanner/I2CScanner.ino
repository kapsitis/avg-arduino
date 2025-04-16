#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial); // For Leonardo/Micro
  Serial.println("I2C scan...");
  for (byte address = 1; address < 128; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      delay(10);
    }
  }
  Serial.println("Scan complete.");
}

void loop() {}