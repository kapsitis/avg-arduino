const int pins[3] = {8, 9, 10}; // A=8, B=9, C=10

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
  for(int i=0;i<3;i++) pinMode(pins[i],INPUT);
}

// void offAll() {
//   for(int i=0;i<3;i++) {
//     pinMode(pins[i], OUTPUT);
//     digitalWrite(pins[i], LOW);
//   }
// }

void loop() {
  for(int i=0;i<6;i++) {
    offAll();
    pinMode(pins[leds[i].pin_high], OUTPUT);
    pinMode(pins[leds[i].pin_low], OUTPUT);
    digitalWrite(pins[leds[i].pin_high], HIGH);
    digitalWrite(pins[leds[i].pin_low], LOW);
    delay(500); // On for 0.5s
  }
}


// const int pins[] = {8, 9, 10}; // Adjust as needed

// // Each LED is defined as (from_pin, to_pin)
// struct CharlieLED {
//   int from;
//   int to;
// };

// // Listing all possible ordered pairs (no repeats, both directions)
// CharlieLED charlie_leds[] = {
//   {0, 1}, // A->B
//   {1, 0}, // B->A
//   {0, 2}, // A->C
//   {2, 0}, // C->A
//   {1, 2}, // B->C
//   {2, 1}, // C->B
// };
// const int N_LEDS = sizeof(charlie_leds)/sizeof(CharlieLED);

// void setup() {}

// void loop() {
//   for (int i=0; i<N_LEDS; i++) {
//     // Set all pins to input first
//     for (int p=0; p<3; p++) pinMode(pins[p], INPUT);

//     int from_pin = pins[charlie_leds[i].from];
//     int to_pin = pins[charlie_leds[i].to];

//     pinMode(from_pin, OUTPUT);
//     digitalWrite(from_pin, HIGH);

//     pinMode(to_pin, OUTPUT);
//     digitalWrite(to_pin, LOW);

//     delay(500); // 0.5 seconds per LED

//     // Turn off all LEDs before next
//     for (int p=0; p<3; p++) pinMode(pins[p], INPUT);
//     delay(100);
//   }
// }