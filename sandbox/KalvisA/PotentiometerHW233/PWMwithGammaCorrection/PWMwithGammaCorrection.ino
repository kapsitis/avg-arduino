void setup() {
    pinMode(9, OUTPUT);
}

    
int mapToPerceivedBrightness(int potValue) {
    // Adjust using a simple power function for gamma correction
    float scaledValue = potValue / 1023.0;
    float correctedValue = pow(scaledValue, 2.2); // Gamma correction
    return int(correctedValue * 255);
}

int mapLinear(int potValue) {
  return potValue / 4;
}
  
void loop() {
    int potValue = analogRead(A0);
    int pwmValue = mapToPerceivedBrightness(potValue);
    // int pwmValue = mapLinear(potValue);
    analogWrite(9, pwmValue);
}
