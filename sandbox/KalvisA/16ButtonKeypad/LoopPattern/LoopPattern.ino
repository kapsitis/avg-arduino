const int pins[4] = {11, 10, 9, 8}; // A,B,C,D

struct Led {
  int pin1;
  int pin2;
};

Led leds[6] = {
  {0,1}, // AB
  {0,2}, // AC
  {0,3}, // AD
  {1,2}, // BC
  {1,3}, // BD
  {2,3}, // CD
};

void setup() {
  // Arduino kontaktus konfigurēsim ciklā "loop"
}

void loop() {
  for (int i=0; i<6; i++) {
    // Uzliek visus kontaktus INPUT režīmā (tie ir atvienoti jeb "free")
    for (int j=0;j<4;j++) pinMode(pins[j], INPUT);

    // Pašreizējam LED uzstāda pin1 = HIGH, pin2 = LOW
    pinMode(pins[leds[i].pin1], OUTPUT);
    digitalWrite(pins[leds[i].pin1], HIGH);
    pinMode(pins[leds[i].pin2], OUTPUT);
    digitalWrite(pins[leds[i].pin2], LOW);
  
    delay(1000); // gaida 1 sekundi

    // Atvieno visu un gaida 100 milisekundes, lai lampiņu gaismas nepārklātos
    for (int j=0;j<4;j++) pinMode(pins[j], INPUT);
    delay(100);
  }
}