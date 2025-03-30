// const byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
    //                      A, B, C, D, E, F, G, DP   
const byte segmentPins[] = {4, 5, 7, 8, 9, 3, 2, 6};

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
}

void displayNumber(byte number) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(segmentPins[j], numbers[number][j]);
    }
    delay(5); // Short delay
}

void loop() {
  int numbers[] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
  for (unsigned int k = 0; k < 16; k++) {
    for (int aa = 0; aa < 50; aa++) {
      displayNumber(numbers[k]);
    }
    delay(1000);
  }
}