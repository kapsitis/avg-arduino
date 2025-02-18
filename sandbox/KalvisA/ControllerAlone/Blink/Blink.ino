/*
  Blink

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);
  delay(2000); 
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(2000); 
  digitalWrite(13, LOW);
  delay(500);
}
