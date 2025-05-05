#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


// Video: https://youtu.be/P42ICrgAtS4?si=9dKE-FxmnaJGdqaO
// Code: https://circuitjournal.com/how-to-use-the-dfplayer-mini-mp3-module-with-an-arduino

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_RX = 0; // Connects to module's TX
static const uint8_t PIN_MP3_TX = 1; // Connects to module's RX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);


  pinMode(PIN_MP3_RX, INPUT);
  pinMode(PIN_MP3_TX, OUTPUT);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);
    // Play the "0001.mp3" in the "mp3" folder on the SD card
    // player.playMp3Folder(1);
    player.playFolder(4, 2);

    // while (true) {
    // int xValue = analogRead(A0);
    // int yValue = analogRead(A1);
    // Serial.print(xValue);
    // Serial.print(",");
    // Serial.println(yValue);
    // delay(20);
    // }

  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop() {
}