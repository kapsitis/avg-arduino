// Pin assignments
const int colPins[4] = {2, 3, 4, 5};    // Columns C1-C4 (Arduino digital pins)
const int rowPins[4] = {A0, A1, A2, A3}; // Rows R1-R4 (Arduino analog pins as digital)

// Scan and print pressed buttons
void setup() {
  Serial.begin(9600);

  // Initialize pins
  for (int c = 0; c < 4; c++) {
    pinMode(colPins[c], OUTPUT);
    digitalWrite(colPins[c], HIGH);  // Set all columns HIGH (inactive)
  }
  for (int r = 0; r < 4; r++) {
    pinMode(rowPins[r], INPUT_PULLUP);  // Use internal pullups
  }
}

void loop() {
  for (int c = 0; c < 4; c++) {
    // Activate this column by pulling it LOW
    digitalWrite(colPins[c], LOW);

    // Check each row
    for (int r = 0; r < 4; r++) {
      if (digitalRead(rowPins[r]) == LOW) {
        Serial.print("Button at Row ");
        Serial.print(r+1);
        Serial.print(", Column ");
        Serial.print(c+1);
        Serial.println(" is pressed.");
        delay(200); // Debounce delay
      }
    }

    // Deactivate column
    digitalWrite(colPins[c], HIGH);
  }
}