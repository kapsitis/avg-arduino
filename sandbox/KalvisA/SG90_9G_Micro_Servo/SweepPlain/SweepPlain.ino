// const int servoPin = 9;        // Pin connected to the servo
// const int sweepDelay = 15;     // Delay between each step, in milliseconds



// // Constants
const int servoPin = 9;  // Pin connected to the servo
const int minPulseWidth = 544;  // Minimum pulse width in microseconds
const int maxPulseWidth = 2400; // Maximum pulse width in microseconds
const int sweepDelay = 150;      // Delay between each degree swept, in milliseconds

// // Function to write the pulse to servo
void writeServo(int angle) {
  int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delay(20 - pulseWidth / 1000);  // Refresh period of 20ms minus pulse
}


// void writeServo(int angle) {
//   int dutyCycle = map(angle, 0, 180, 26, 128);  // Map angle to duty cycle
//   analogWrite(servoPin, dutyCycle);
// }

void setup() {
  pinMode(servoPin, OUTPUT);  // Set the servo pin as an output
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int angle = -90; angle <= 90; angle++) {
    writeServo(angle);
    delay(sweepDelay);
  }

  // Sweep from 180 to 0 degrees
  for (int angle = 90; angle >= -90; angle--) {
    writeServo(angle);
    delay(sweepDelay);
  }
}


// // Constants
// const int servoPin = 9;  // Pin connected to the servo
// const int minPulseWidth = 544;  // Minimum pulse width in microseconds
// const int maxPulseWidth = 2400; // Maximum pulse width in microseconds
// const int sweepDelay = 15;      // Delay between each degree swept, in milliseconds

// // Function to write the pulse to servo
// void writeServo(int angle) {
//   int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
//   digitalWrite(servoPin, HIGH);
//   delayMicroseconds(pulseWidth);
//   digitalWrite(servoPin, LOW);
//   delay(20 - pulseWidth / 1000);  // Refresh period of 20ms minus pulse
// }

// void setup() {
//   // Set the servo pin as an output
//   pinMode(servoPin, OUTPUT);
// }

// void loop() {
//   // Sweep from 0 to 180 degrees
//   for (int angle = 0; angle <= 180; angle++) {
//     writeServo(angle);
//     delay(sweepDelay);
//   }

//   // Sweep from 180 to 0 degrees
//   for (int angle = 180; angle >= 0; angle--) {
//     writeServo(angle);
//     delay(sweepDelay);
//   }
// }