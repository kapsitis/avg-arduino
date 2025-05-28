const int pins[3] = {16, 17, 18}; // A=16, B=17, C=18

struct CharlieLED {
  int pin_high; // Pin to OUTPUT HIGH
  int pin_low;  // Pin to OUTPUT LOW
  int pin_z;    // Pin to INPUT (high Z)
};
CharlieLED leds[6] = {
  {0,1,2},  // LED1: A HIGH, B LOW, C Z
  {1,0,2},  // LED2: B HIGH, A LOW, C Z
  {0,2,1},  // LED3: A HIGH, C LOW, B Z
  {2,0,1},  // LED4: C HIGH, A LOW, B Z
  {1,2,0},  // LED5: B HIGH, C LOW, A Z
  {2,1,0},  // LED6: C HIGH, B LOW, A Z
};

void setup() {}

void offAll() {
  for (int i = 0; i < 3; i++) pinMode(pins[i], INPUT);
}

void loop() {
  for (int i = 0; i < 6; i++) {
    offAll();
    pinMode(pins[leds[i].pin_high], OUTPUT);
    pinMode(pins[leds[i].pin_low], OUTPUT);
    digitalWrite(pins[leds[i].pin_high], HIGH);
    digitalWrite(pins[leds[i].pin_low], LOW);
    delay(500); // On for 0.5s
  }
}