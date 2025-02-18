//const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // A, B, C, D, E, F, G, DP
//const int digitPins[] = {10, 11, 12, 13}; // D1, D2, D3, D4

const int segmentPins[] = {9, 3, 5, 7, 8, 2, 4, 6}; // A, B, C, D, E, F, G, DP
const int digitPins[] = {10, 11, 12, 13}; // D1, D2, D3, D4

const byte numbers[16][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}, // 9
  {1,1,1,0,1,1,1,0}, // A
  {0,0,1,1,1,1,1,0}, // B
  {1,0,0,1,1,1,0,0}, // C
  {0,1,1,1,1,0,1,0}, // D
  {1,0,0,1,1,1,1,0}, // E
  {1,0,0,0,1,1,1,0} // F
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Turn off digits
  }
}

void displayNumber(int number) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], LOW); // Enable current digit
    for (int j = 0; j < 8; j++) {
      digitalWrite(segmentPins[j], numbers[number % 16][j]);
    }
    delay(5); // Short delay
    digitalWrite(digitPins[i], HIGH); // Disable current digit
    number /= 16;
  }
}

void loop() {
  int numbers[] = {0x0000, 0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777, 0x8888, 0x9999, 0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD, 0xEEEE, 0xFFFF};
  for (int k = 0; k < 16; k++) {
    for (int aa = 0; aa < 50; aa++) {
      displayNumber(numbers[k]);
    }
    delay(1000);
  }
}