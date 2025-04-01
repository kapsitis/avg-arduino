#include <Servo.h>

Servo myservo;  

const int pinAnalog = A0;
const int clockwiseLED = 10; // sarkanā LED diode
const int counterClockwiseLED = 11; // zaļā LED diode

void setup() {
    // myservo objekts klausīsies 9.kontaktu
    myservo.attach(9);
    // Paziņojam, ka 10. un 11.kontaktus lietos izvadei
    pinMode(clockwiseLED, OUTPUT);
    pinMode(counterClockwiseLED, OUTPUT);
}

void loop() {
    // potenciometra vērtība no [0;1023]
    int valInt = analogRead(pinAnalog);
    // mērogojam to tā, lai būtu intervālā [0;180]
    int valAngle = map(valInt, 0, 1023, 0, 180); 
    // pagriež servomotoru uz šo leņķi
    myservo.write(valAngle);
    if (valAngle > 90) {
      digitalWrite(counterClockwiseLED, LOW);
      digitalWrite(clockwiseLED, HIGH);
    } else {
      digitalWrite(counterClockwiseLED, HIGH);
      digitalWrite(clockwiseLED, LOW);
    }
    // pagaida, kamēr motors aizgriežas līdz šai vietai
    delay(15); 
}
