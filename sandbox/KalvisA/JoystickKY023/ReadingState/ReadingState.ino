// KY-023 Joystick Module Interface
const int pinSW = 2;    // Digital pin for switch/button
const int pinVRX = A0;   // Analog pin for X-axis
const int pinVRY = A1;   // Analog pin for Y-axis

int xValue = 0;          // Stores X-axis value
int yValue = 0;          // Stores Y-axis value
int swValue = 0;         // Stores switch/button state

void setup() {
  pinMode(pinSW, INPUT_PULLUP); // Enable internal pull-up resistor for the switch
  
  Serial.begin(9600);     // Initialize serial communication
}

void loop() {
  // Read all values
  xValue = analogRead(pinVRX);
  yValue = analogRead(pinVRY);
  swValue = 256*digitalRead(pinSW);
  
  // Send data to Serial Plotter in CSV format
  Serial.print(xValue);
  Serial.print(",");
  Serial.print(yValue);
  Serial.print(",");
  Serial.println(swValue);
  
  // Small delay to avoid flooding the serial port
  delay(20);
}