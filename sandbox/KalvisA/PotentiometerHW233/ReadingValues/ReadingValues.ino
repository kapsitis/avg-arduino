const int pinAnalog = A0;

void setup(void) {
    Serial.begin(9600); 
}

void loop(void) {
    int valInt = analogRead(pinAnalog); 
    double valU = (5. / 1023) * valInt;
    String separator = " spriegums:";
    Serial.print(valInt);
    Serial.print(" ");
    Serial.print(A0);
    Serial.print(separator); 
    Serial.println(valU , 2); 
    delay(100);
}

