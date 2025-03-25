#include <Servo.h>

Servo myServo;  // Create a servo object

void setup() {
  myServo.attach(9);  // Attach the servo to pin 9
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) { // Sweep from 0 to 180 degrees
    myServo.write(pos);               // Set the servo position
    delay(15);                        // Wait for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // Sweep back from 180 to 0 degrees
    myServo.write(pos);               
    delay(15);
  }
}