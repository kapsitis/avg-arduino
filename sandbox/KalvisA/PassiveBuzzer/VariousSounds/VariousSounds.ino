const int BUZZER_PIN = 8;
const int buttonPins[] = {5, 6, 7}; // Pogas

const float sounds[] = {261.6, 277.2, 293.7, 311.1, 329.6, 349.2, 370.0, 392.0, 415.3, 440.0, 466.2, 493.9, 523.3};

int currentState = 0; 

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
        if (digitalRead(buttonPins[i]) == LOW && currentState != buttonPins[i]) {
            currentState = buttonPins[i]; 
            Serial.println(currentState);
        }     
    }
    return currentState; 
}

void loop() {
  int state = currentState;

  if (state == 5) {
    for (int j = 0; j < 12; j++) {
      tone(BUZZER_PIN, sounds[j]); 
      delay(250);
      currentState = resetActive(); 
      if (state != currentState) return; 
    }
    for (int j = 12; j >= 0; j--) {
      tone(BUZZER_PIN, sounds[j]); 
      delay(250);
      currentState = resetActive(); 
      if (state != currentState) return; 
    }
  }
  else if (state == 6) {
  int eightDuration = 500; // astotdaļnots ilgums (ms)
  tone(BUZZER_PIN, sounds[0]); 
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[2]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[4]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[5]);
  delay(eightDuration);
  currentState = resetActive(); 
  if (state != currentState) return; 
  tone(BUZZER_PIN, sounds[7]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[4]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[0]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[4]);
  delay(eightDuration);
  currentState = resetActive(); 
  if (state != currentState) return; 
  tone(BUZZER_PIN, sounds[7]);
  delay(2*eightDuration);
  tone(BUZZER_PIN, sounds[9]);
  delay(2*eightDuration);
  currentState = resetActive(); 
  if (state != currentState) return; 
  tone(BUZZER_PIN, sounds[7]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[4]);
  delay(eightDuration);
  tone(BUZZER_PIN, sounds[0]);
  delay(2*eightDuration);
  noTone(BUZZER_PIN); 
  delay(2*eightDuration);
  }

  else {
    for(int i=100 ; i<2000 ; i++){ // loop for to increase the sound frequency
         tone(BUZZER_PIN, i);
         delay(10); //You can change the delay if you want to make it longer or shorter
         currentState = resetActive(); 
        if (state != currentState) return; 
    }
    for(int i=2000 ; i>100 ; i--){
         tone(BUZZER_PIN, i);
         delay(10);
          currentState = resetActive(); 
          if (state != currentState) return; 
    } 
  }
}
