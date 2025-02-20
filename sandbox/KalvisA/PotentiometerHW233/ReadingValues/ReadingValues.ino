const int pinAnalog = A0;

void setup(void) {
    Serial.begin (9600); 
}

void loop(void) {
    int valInt = analogRead(pinAnalog); 
    double valU = 5./1024.* valInt;
    Serial.print(valInt); 
    Serial.print(" "); 
    Serial.println(valU , 2); 
    delay(100);
}

