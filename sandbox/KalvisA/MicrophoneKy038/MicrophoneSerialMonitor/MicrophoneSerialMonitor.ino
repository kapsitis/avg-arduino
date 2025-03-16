const int analogPin = A1; // Pin where analog output is connected
const int digitalPin = 2; // Pin where digital output is connected

void setup() {
    Serial.begin(9600); // Initialize serial communication at 9600 baud rate
    pinMode(digitalPin, INPUT); // Set digital pin as input
}

void loop() {
    // Read and print the analog value
    int analogValue = analogRead(analogPin);
    Serial.print("Analog Value: ");
    Serial.println(analogValue);

    // Read and print the digital value
    int digitalValue = digitalRead(digitalPin);
    Serial.print("Digital Trigger: ");
    Serial.println(digitalValue ? "YES" : "NO");

    delay(500); // Wait half a second for the next reading
}