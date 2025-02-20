const int pinAnalog = A0;

const int buzzerPin = 8;

void setup(void) {
    Serial.begin (9600); 
    tone(buzzerPin, 1000, 2000);
}

void loop(void) {
    int valInt = analogRead(pinAnalog); 
    double valU = 5./1024.* valInt;
    Serial.print(valInt); 
    Serial.print(" "); 
    Serial.println(valU , 2); 
    delay(100);

    if (valInt > 500) {
        tone(buzzerPin, 440); // A4
        delay(1000);

        tone(buzzerPin, 494); // B4
        delay(1000);

        tone(buzzerPin, 523); // C4
        delay(1000);
    }
}

