#include <Servo.h>

Servo myServo;
const int clockwiseLED = 10; // sarkanā LED diode
const int counterClockwiseLED = 11; // zaļā LED diode
const int neutralLED = 12; // 

// Servomotora virzieni
const int NEUTRAL_POS = 90; // "neitrālais" virziens
const int RIGHT_POS = 100;  // 10 grādi pulksteņa rādītāju virzienā no neitrālā
const int LEFT_POS = 80;    // 10 grādi pretēji pulksteņa rādītāju virzienam no neitrālā

void setup() {
    // Servomotora dzeltenais vadiņš klausās 9.kontaktu
    myServo.attach(9);
    // Paziņojam, ka 10. un 11.kontaktus lietos izvadei
    pinMode(clockwiseLED, OUTPUT);
    pinMode(counterClockwiseLED, OUTPUT);
}

void loop() {
    // Griežas 10 grādus pretēji pulksteņa rādītājiem
    digitalWrite(counterClockwiseLED, HIGH);
    digitalWrite(clockwiseLED, LOW);
    digitalWrite(neutralLED, LOW);
    myServo.write(LEFT_POS);
    delay(2000);  // gaida 1 sekundi

    // Atgriežas neitrālā stāvoklī
    digitalWrite(counterClockwiseLED, LOW);
    digitalWrite(clockwiseLED, LOW);
    digitalWrite(neutralLED, HIGH);
    myServo.write(NEUTRAL_POS);
    delay(2000);  // gaida 1 sekundi

    // Griežas 10 grādus pulksteņa rādītāju virzienā
    digitalWrite(counterClockwiseLED, LOW);
    digitalWrite(clockwiseLED, HIGH);
    digitalWrite(neutralLED, LOW);
    myServo.write(RIGHT_POS);
    delay(2000);  // gaida 1 sekundi

    // Move back to Neutral
    digitalWrite(counterClockwiseLED, LOW);
    digitalWrite(clockwiseLED, LOW);
    digitalWrite(neutralLED, HIGH);
    myServo.write(NEUTRAL_POS);
    delay(2000);  // gaida 1 sekundi
}