#include <Servo.h>

Servo myservo;  

const int pinAnalog = A0;

void setup() {
    // myservo objekts klausīsies 9.kontaktu
    myservo.attach(9);  
    Serial.begin(9600); 
}

void loop() {
    // potenciometra vērtība no [0;1023]
    int valInt = analogRead(pinAnalog);
    Serial.print(valInt);
    // mērogojam to tā, lai būtu intervālā [0;180]
    int valAngle = map(valInt, 0, 1023, 0, 180); 
    // pagriež servomotoru uz šo leņķi
    myservo.write(valAngle);
    // pagaida, kamēr motors aizgriežas līdz šai vietai
    delay(15); 
}
