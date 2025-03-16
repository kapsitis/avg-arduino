const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);   // Ieslēdz diodi
    delay(1000);                  // Gaida 1000 milisekundes (1 sekundi)
    digitalWrite(ledPin, LOW);    // Izslēdz diodi
    delay(1000);                  // Gaida 1000 milisekundes
}

