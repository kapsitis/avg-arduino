#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX (Arduino pins)

void setup() {
  Serial.begin(9600);        // For serial monitor
  BTSerial.begin(9600);      // Default baud rate for HC-05
  Serial.println("Waiting for Bluetooth message...");
}

void loop() {
  // Read from HC-05 and print to Serial
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.write(c);         // Print Bluetooth message to Serial Monitor
  }

  // This part is optional, lets you send from Serial Monitor to Bluetooth:
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}