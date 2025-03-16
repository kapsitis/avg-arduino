const int pinAnalog = A0;
const int ledPin = 13;

void setup(void) {
//    Serial.begin (9600); 
}

void loop(void) {
    int valInt = 1000;
    // int valInt = analogRead(pinAnalog); 
    // double valU = 5./1024.* valInt;
    // Serial.print(valInt); 
    // Serial.print(" "); 
    // Serial.println(valU , 2); 
    delay(1000);

    if (valInt >= 512) {
        digitalWrite(ledPin, HIGH);   // Ieslēdz diodi
    }
    else {
        digitalWrite(ledPin, LOW);   // Ieslēdz diodi
    }
}

