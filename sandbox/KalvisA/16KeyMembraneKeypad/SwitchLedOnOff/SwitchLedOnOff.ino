#include <Keypad.h>

// Here pins of the 4x4 keypad are connected to the digital pins D2...D9. 
// Moreover, the LED (along with a 220 Ohm resistor) 
// is connected to the digital pin D13 and the ground. 
// TODO: For some reason, just the digits 3,6,9 work for switching on, 
// A,B,C work for switching off. 

// Define the keypad size
const byte ROWS = 4;
const byte COLS = 4;

// Define the key mapping
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect keypad rows and columns to these Arduino pins
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

// Create an instance of the Keypad class
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the diode pin
const int diodePin = 13;

void setup() {
  // Set the diodePin as an output pin
  pinMode(diodePin, OUTPUT);
  // Start with the diode off
  digitalWrite(diodePin, LOW);
}

void loop() {
  // Get the key being pressed
  char key = keypad.getKey();

  // If a key is pressed, check if it's a digit or not
  if (key) {
    if (key >= '0' && key <= '9') {
      // If it's a digit, turn the diode on
      digitalWrite(diodePin, HIGH);
    } else {
      // If it's not a digit, turn the diode off
      digitalWrite(diodePin, LOW);
    }
  }
}