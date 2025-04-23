const int BUZZER_PIN = 8;
const int buttonPins[] = {5, 6, 7}; // Corresponding buttons

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
    for (int i = 0; i < 3; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

int resetActive() {
    int current = 0; 
    for (int i = 0; i < 3; i++) {
        if (digitalRead(buttonPins[i]) == LOW && current != buttonPins[i]) {
            current = buttonPins[i]; 
            Serial.println(current);
        }     
    }
    return current; 
}

void loop() {
    for(int i=100 ; i<2000 ; i++){ // loop for to increase the sound frequency
         tone(BUZZER_PIN, i);
         delay(10); //You can change the delay if you want to make it longer or shorter
    }
    for(int i=2000 ; i>100 ; i--){
         tone(BUZZER_PIN, i);
         delay(10);
    } 
    // while (true) {
    //     if (resetActive() != 5) break;
    //     tone(BUZZER_PIN, 440); // 1.oktāvas LA
    //     delay(1000);
    //     if (resetActive() != 5) break;
    //     tone(BUZZER_PIN, 880); // 2.oktāvas LA (divreiz lielāka frekvence)
    //     delay(1000);
    //     noTone(BUZZER_PIN);
    // }
}
