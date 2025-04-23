int buttonPin = 2;
int pressCount = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Button pressed (active LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    pressCount++;
    Serial.println(pressCount);
    delay(1); // a short pause so serial monitor is readable
  }
  lastButtonState = buttonState;
}