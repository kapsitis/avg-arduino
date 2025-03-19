const int pinAnalog = A0;

void setup(void) {
    pinMode(LED_BUILTIN, OUTPUT); 
    Serial.begin(9600); 
}

void loop(void) {
    int valInt = analogRead(pinAnalog); 
    Serial.println(valInt);
    if (valInt >= 512) { // mirkšķina diodi
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }
    else { // izslēdz diodi
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);    
    }
}

