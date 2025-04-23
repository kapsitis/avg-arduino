#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  Serial.begin(9600);
  Serial.println("7 Segment Display Test");
  
  if (!matrix.begin(0x70)) {
    Serial.println("Display not found!");
    while (1);
  }
  matrix.setBrightness(1);
}

void loop() {
  int digit = 0; 

  for (int i=0; i<10000; i++) {
    matrix.clear();
    int d0 = i % 10;
    int d1 = (i / 10) % 10;
    int d2 = (i / 100) % 10;
    int d3 = (i / 1000) % 10;

    matrix.writeDigitNum(3, d0);
    matrix.writeDigitNum(2, d1);
    matrix.writeDigitNum(1, d2);
    matrix.writeDigitNum(0, d3);


    matrix.writeDisplay();
    delay(100);
  }
}
