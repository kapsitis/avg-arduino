const int BUZZER_PIN = 8;
const int numRounds = 10;
const int ledPins[] = {2, 3, 4}; // Red, Green, Blue LEDs
const int buttonPins[] = {5, 6, 7}; // Corresponding buttons
unsigned long reactionTimes[numRounds];
int successfulMatches = 0;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
    for (int i = 0; i < 3; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    randomSeed(analogRead(0)); // nejaušu skaitļu ģenerators
}

void loop() {
    // Reakciju mēra 10 reizes
    for (int round = 0; round < numRounds; round++) {
        int selectedLED = random(0, 3); // nejauši izvēlas lampiņu
        int tones[] = {440, 494, 554};
        digitalWrite(ledPins[selectedLED], HIGH); // ieslēdz lampiņu
        tone(BUZZER_PIN, tones[selectedLED]); // ieslēdz pīkstētāju
        
        unsigned long startTime = millis();
        bool matched = false;
        
        unsigned long reactionTime = 500;
        
        while (!matched) {
            for (int i = 0; i < 3; i++) {
                if (digitalRead(buttonPins[i]) == LOW) {
                    if (i == selectedLED) {
                        matched = true;
                        reactionTime = millis() - startTime;
                        reactionTimes[round] = reactionTime;
                        successfulMatches++;
                        matched = true;
                        break;
                    }
                    else {
                        delay(100);
                    }
                }
                else if (millis() - startTime >= 500) {
                    reactionTimes[round] = 500;
                    matched = true;
                    break;
                }
            }
            if (matched) {
                // Serial.print("ReactionTime: ");
                Serial.println(reactionTimes[round]);
                break;
            }
        }


        noTone(BUZZER_PIN);
        digitalWrite(ledPins[selectedLED], LOW);

        int pause = random(2000, 6000);
        delay(pause); 
    }

    delay(10000);
    for (int i = 0; i < 3; i++) {
        tone(BUZZER_PIN, 440);
        delay(50);
        noTone(BUZZER_PIN);
        delay(1500);
    }
}