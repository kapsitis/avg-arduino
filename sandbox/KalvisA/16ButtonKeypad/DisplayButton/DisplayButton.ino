#include <Keypad.h>

const byte ROWS = 4; // Rindiņas
const byte COLS = 4; // Kolonnas

// Pieraksta simbolus katrai pogai
char keys[ROWS][COLS] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', 'E', 'F', '0'}
};

// Savieno R1, R2, R3, R4 ar šiem Arduino kontaktiem:
byte rowPins[ROWS] = {5, 4, 3, 2};

// Savieno C1, C2, C3, C4 ar šiem Arduino kontaktiem:
byte colPins[COLS] = {6, 7, 8, 9};

// Izveido Keypad objektu
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.println(key);
  }
}