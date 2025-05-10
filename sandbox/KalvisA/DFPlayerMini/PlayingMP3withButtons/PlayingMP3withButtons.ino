//Very much inspired by https://www.dfrobot.com/blog-1462.html by DFRobot Feb 26 2020
//Additions made by Just Baselmans https://www.youtube.com/justbaselmansYT Jan 23 2023

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include <Keypad.h>



const byte ROWS = 4;  // Rindiņas
const byte COLS = 4;  // Kolonnas

// Pieraksta simbolus katrai pogai
char keys[ROWS][COLS] = {
  { '1', '2', '3', '4' },
  { '5', '6', '7', '8' },
  { '9', 'A', 'B', 'C' },
  { 'D', 'E', 'F', '0' }
};

// Savieno R1, R2, R3, R4 ar šiem Arduino kontaktiem:
byte rowPins[ROWS] = { 3, 2, 1, 0 };
// Savieno C1, C2, C3, C4 ar šiem Arduino kontaktiem:
byte colPins[COLS] = { 4, 5, 6, 7 };
// Izveido Keypad objektu
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void menu_options() {
  Serial.println();
  Serial.println(F("=================================================================================================================================="));
  Serial.println(F("Commands:"));
  Serial.println(F(" [1-9] To select the MP3 file"));
  Serial.println(F(" [fXsY] Play song from folder X, song Y"));
  Serial.println(F(" [s] stopping reproduction"));
  Serial.println(F(" [p] pause/continue music"));
  Serial.println(F(" [r] toggle repeat mode"));
  Serial.println(F(" [vX] set volume to X"));
  Serial.println(F(" [+ or -] increases or decreases the volume"));
  Serial.println(F(" [< or >] forwards or backwards the track"));
  Serial.println();
  Serial.println(F("================================================================================================================================="));
}

// https://youtu.be/7WiSeQxb1bU?si=CaB-BQzUbNjLS_mt
// One more thing: https://youtu.be/jyQQi-ay8cs?si=geeS8Glqh3fiJ-cy

// Initialize software serial on pins 10 and 11
SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;
String line;
char command;
int pause = 0;
int repeat = 0;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);



  // // Pārbauda, vai DFPlayer modulis atbild
  // Serial.println();
  // Serial.println(F("DFRobot DFPlayer Mini"));
  // Serial.println(F("Initializing DFPlayer module ... Wait!"));

  // if (!myDFPlayer.begin(mySoftwareSerial)) {
  //   Serial.println(F("Not initialized:"));
  //   Serial.println(F("1. Check the DFPlayer Mini connections"));
  //   Serial.println(F("2. Insert an SD card"));
  //   while (true)
  //     ;
  // }
  // Serial.println();
  // Serial.println(F("DFPlayer Mini module initialized!"));
  // myDFPlayer.setTimeOut(500); // Serial timeout 500ms
  // myDFPlayer.volume(10);      // Skaļums = 10 (max = 30)
  // myDFPlayer.EQ(0);           // Normal equalization
  // //  myDFPlayer.EQ(DFPLAYER_EQ_POP);
  // //  myDFPlayer.EQ(DFPLAYER_EQ_ROCK);
  // //  myDFPlayer.EQ(DFPLAYER_EQ_JAZZ);
  // //  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  // //  myDFPlayer.EQ(DFPLAYER_EQ_BASS);
  // menu_options();
}

int currentVolume = 0;

int currentFolder = 1;
int currentSong = 1;


void loop() {

  while (true) {
    int volume = analogRead(A0) / 34;
    char key = keypad.getKey();

    if (key) {
      Serial.print("key = ");
      Serial.println(key);

      if (key == '1') {
        command = 'p';
        Serial.println("Komanda: Play");
      } else if (key == '2') {
        command = 'p';
        Serial.println("Komanda: Pause");
      } else if (key == '3') {
        command = 's';
        Serial.println("Komanda: Stop");
      } else if (key == '4') {
        command = 'r';
        Serial.println("Komanda Repeat");
      } else if (key == '5') {
        command = '+';
        Serial.println("Komanda Volume Up (skaļāk)");
      } else if (key == '6') {
        command = '-';
        Serial.println("Komanda Volume Down (klusāk)");
      } else if (key == '7') {
        command = '-';
        Serial.println("Komanda < (iepriekšējais fails)");
      } else if (key == '8') {
        command = '-';
        Serial.println("Komanda < (nākamais fails)");
      }
    } else if (currentVolume != volume) {
      currentVolume = volume;
      command = 'v';
      Serial.println("Komanda V (mainīt skaļumu)");
    }

    //Play from specific folder
    if (command == 'p') {
      Serial.print("From folder: ");
      Serial.print(currentFolder);
      Serial.print(", playing song: ");
      Serial.println(currentSong);
      myDFPlayer.playFolder(currentFolder, currentSong);  //play specific mp3 in SD:/folder/song.mp3; Folder Name(1~99); File Name(1~255)
      menu_options();
    }



    // Reproduction
    // Stop
    if (command == 's') {
      myDFPlayer.stop();
      Serial.println("Stop Playing...");
      menu_options();
    }

    // Pause/Continue the music
    if (command == 'p') {
      pause = !pause;
      if (pause == 0) {
        Serial.println("Continue...");
        myDFPlayer.start();
      }
      if (pause == 1) {
        Serial.println("Music Paused!");
        myDFPlayer.pause();
      }
      menu_options();
    }

    // Toggle repeat mode
    if (command == 'r') {
      repeat = !repeat;
      if (repeat == 1) {
        myDFPlayer.enableLoop();
        Serial.println("Repeat mode enabled.");
      } else {
        myDFPlayer.disableLoop();
        Serial.println("Repeat mode disabled.");
      }
      menu_options();
    }

    // Set volume
    if (command == 'v') {
      if (currentVolume >= 0 && currentVolume <= 30) {
        myDFPlayer.volume(currentVolume);
        Serial.print("Current Volume:");
        Serial.println(myDFPlayer.readVolume());
      } else {
        Serial.println("Invalid volume level, choose a number between 0-30.");
      }
      menu_options();
    }

    // Increases volume
    if (command == '+') {
      myDFPlayer.volumeUp();
      Serial.print("Current Volume:");
      currentVolume = myDFPlayer.readVolume();
      Serial.println(currentVolume);
      menu_options();
    }
    // Decreases volume
    if (command == '-') {
      myDFPlayer.volumeDown();
      Serial.print("Current Volume:");
      currentVolume = myDFPlayer.readVolume();
      Serial.println(currentVolume);
      menu_options();
    }

    // Play previouse
    if (command == '<') {
      myDFPlayer.previous();
      Serial.println("Previous:");
      Serial.print("Current track:");
      Serial.println(myDFPlayer.readCurrentFileNumber() - 1);
      menu_options();
    }

    // Play next
    if (command == '>') {
      myDFPlayer.next();
      Serial.println("Next:");
      Serial.print("Current track:");
      Serial.println(myDFPlayer.readCurrentFileNumber() + 1);
      menu_options();
    }
  }
}
