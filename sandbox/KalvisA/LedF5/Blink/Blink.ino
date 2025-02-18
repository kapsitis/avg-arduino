// Define the pin where the LED is connected
const int ledPin = 13;

void setup() {
    // Initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);   // Turn the LED on
    delay(1000);                  // Wait for a second
    digitalWrite(ledPin, LOW);    // Turn the LED off
    delay(1000);                  // Wait for a second
}

