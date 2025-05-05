#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(2, 3);  // RX (to DFPlayer TX), TX (to DFPlayer RX)
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer module ... Wait!"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Not initialized:"));
    Serial.println(F("1. Check the DFPlayer Mini connections"));
    Serial.println(F("2. Insert an SD card"));
    while (true)
      ;
  }
  Serial.println();
  Serial.println(F("DFPlayer Mini module initialized!"));

  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30);
  myDFPlayer.EQ(0);

  Serial.println("Commands: p=Play, s=Stop, n=Next, b=Back, +=Vol up, -=Vol down");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'p':
        Serial.println("Playing track 1...");
        myDFPlayer.play(1);
        break;
      case 's':
        Serial.println("Stopping...");
        myDFPlayer.stop();
        break;
      case 'n':
        Serial.println("Next track...");
        myDFPlayer.next();
        break;
      case 'b':
        Serial.println("Previous track...");
        myDFPlayer.previous();
        break;
      case '+':
        Serial.println("Volume up...");
        myDFPlayer.volumeUp();
        break;
      case '-':
        Serial.println("Volume down...");
        myDFPlayer.volumeDown();
        break;
      default:
        Serial.println("Unknown command.");
        break;
    }
  }
}