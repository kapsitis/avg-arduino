const byte rowPins[4] = {2, 3, 4, 5}; // Row pins
const byte colPins[4] = {6, 7, 8, 9}; // Column pins

void setup() {
  Serial.begin(9600);

  // Initialize row pins as outputs
  for (byte i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH); // Set rows HIGH
  }

  // Initialize column pins as inputs with pull-up resistors
  for (byte i = 0; i < 4; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (byte row = 0; row < 4; row++) {
    // Pull the current row LOW
    digitalWrite(rowPins[row], LOW);
    
    for (byte col = 0; col < 4; col++) {
      // Check if the current column is LOW
      if (digitalRead(colPins[col]) == LOW) {
        Serial.print("Key pressed at Row: ");
        Serial.print(row);
        Serial.print(", Column: ");
        Serial.println(col);
        delay(500); // Debounce delay
      }
    }

    // Set the row back to HIGH
    digitalWrite(rowPins[row], HIGH);
  }
}