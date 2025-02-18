const int segmentPins[] = {9, 3, 5, 7, 8, 2, 4, 6}; // A, B, C, D, E, F, G, DP
const int digitPins[] = {10, 11, 12, 13}; // D1, D2, D3, D4

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
 
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Turn off all digits initially
  }
}

void loop() {
  // Example: Light up all segments in the first digit
  digitalWrite(digitPins[3], LOW); // Enable D1
  for (int i = 2; i < 3; i++) { // Turn on all segments
    digitalWrite(segmentPins[i], HIGH);
  }
  digitalWrite(digitPins[3], HIGH); // Disable D1
}