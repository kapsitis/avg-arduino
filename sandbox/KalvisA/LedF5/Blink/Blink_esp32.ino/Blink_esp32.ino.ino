const int ledPin = 2;          // Pin where LED is connected
const int frequency = 20;      // Blinking frequency in Hz
const int interval = 1000 / (2 * frequency); // Calculate interval

void setup() {
  pinMode(ledPin, OUTPUT);     // Set the LED pin as an OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(interval);             // Wait for interval
  digitalWrite(ledPin, LOW);   // Turn LED off
  delay(interval);             // Wait for interval
}