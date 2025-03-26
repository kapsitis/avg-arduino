const int potPin = A0; // A0 nolasa potenciometra vērtību [0;1023]
const int ledPin = 9; // 9.kontakts sūta spriegumu LED+rezistora ķēdei

void setup() {
  Serial.begin(9600); // komunikācija caur seriālo portu
}

void loop() {
  int x = analogRead(potPin); 
  int y = x / 4;  // rakstīt var vērtības intervālā [0;255]
  analogWrite(ledPin, y);

  // Izdrukā vērtības, lai varētu atkļūdot
  Serial.print("Potentiometer Value: ");
  Serial.print(x);
  Serial.print(" => Scaled Value: ");
  Serial.println(y);

  // Drusku pagaida, lai stabilāk lasītu/rakstītu
  delay(10);
}