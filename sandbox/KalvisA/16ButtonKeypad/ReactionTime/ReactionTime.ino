const int numRounds = 10;
const int ledPins[] = {2, 3, 4}; // Red, Green, Blue LEDs
const int buttonPins[] = {5, 6, 7}; // Corresponding buttons
unsigned long reactionTimes[numRounds];
int successfulMatches = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT);
  }
  randomSeed(analogRead(0)); // Seed random generator
}

void loop() {
  for (int round = 0; round < numRounds; round++) {
    int selectedLED = random(0, 3);
    digitalWrite(ledPins[selectedLED], HIGH);

    unsigned long startTime = millis();
    bool matched = false;

    while (!matched) {
      for (int i = 0; i < 3; i++) {
        if (digitalRead(buttonPins[i]) == HIGH) {
          if (i == selectedLED) {
            matched = true;
            unsigned long reactionTime = millis() - startTime;
            reactionTimes[round] = reactionTime;
            successfulMatches++;
          }
          break;
        }
      }
    }

    digitalWrite(ledPins[selectedLED], LOW);
    delay(500);
  }

  unsigned long totalReactionTime = 0;
  for (int i = 0; i < numRounds; i++) {
    totalReactionTime += reactionTimes[i];
  }

  float averageReactionTime = static_cast<float>(totalReactionTime) / numRounds;
  Serial.print("Average Reaction Time: ");
  Serial.print(averageReactionTime);
  Serial.println(" ms");
  
  Serial.print("Precision: ");
  Serial.print(successfulMatches);
  Serial.print(" out of ");
  Serial.println(numRounds);
}