#include <Servo.h>

Servo myServo;  // Servomotora objekts

void setup() {
  myServo.attach(9);  // Griešanas komandas padod no 9.kontakta
}

void loop() {
  // Ciklā ātri maina "pos" vērtības no 0 līdz 180.
  for (int pos = 0; pos <= 180; pos += 1) { 
    // Uzstāda servomotora stāvokli
    myServo.write(pos);
    // Drusku paguļ, lai servomotors var aizkļūt līdz šim stāvoklim      
    delay(15);                        
  }
  // Maina vērtības no 180 atpakaļ līdz 0
  for (int pos = 180; pos >= 0; pos -= 1) { 
    myServo.write(pos);               
    delay(15);
  }
}