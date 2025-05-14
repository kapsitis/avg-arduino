#include <LedControl.h>

#define DEADZONE 100
#define CENTER   512

int xx[] = {0,1,2,3,4};
int yy[] = {0,0,0,0,0};

int headIdx = 4;
int loopVar = 0;

// DIN pin 11, CLK pin 13, CS pin 10, number of devices is 1
LedControl lc=LedControl(11,13,10,1);

int x = 0;
int y = 0;

void setup() {
    lc.shutdown(0,false);    // Wake up MAX7219
    lc.setIntensity(0,1);    // Set brightness (0--15)
    lc.clearDisplay(0);      // Clear display
    randomSeed(analogRead(0)); // nejaušu skaitļu ģenerators
}


unsigned long lastMoveTime = 0;
const unsigned long interval = 200; // 5Hz movement

void loop() {
    unsigned long now = millis();
    if (now - lastMoveTime < interval)
        return;
    lastMoveTime = now;

    // Draw the snake
    for (int row = 0; row < 8; row++) {
        byte pattern = 0b00000000;
        for (int scan = 0; scan < 5; scan++) {
            if (yy[scan] == row) {
                pattern = pattern ^ (1 << xx[scan]);
            }
        }
        lc.setRow(0, row, pattern);
    }

    // Try to move snake
    int direction = random(0, 4);
    int x = xx[headIdx];
    int y = yy[headIdx];
    bool doStep = true;

    if (direction == 0)      x += 1;
    else if (direction == 1) x -= 1;
    else if (direction == 2) y += 1;
    else                     y -= 1;

    if (x < 0 || x > 7 || y < 0 || y > 7)
        doStep = false;

    for (int scan = 0; scan < 5; scan++) {
        if (x == xx[scan] && y == yy[scan]) {
            doStep = false;
        }
    }

    if (doStep) {
        headIdx = (headIdx + 1) % 5;
        xx[headIdx] = x;
        yy[headIdx] = y;
    }
}

// void loop() {
//     loopVar += 1;
//     for (int row = 0; row < 8; row++) {
//         byte pattern = 0b00000000;
//         for (int scan = 0; scan < 5; scan++) {
//             if (yy[scan] == row) {
//                 pattern = pattern ^ (1 << xx[scan]);
//             }
//         }
//         lc.setRow(0, row, pattern);
//     }


//     // int X= analogRead (A0);
//     // int Y=analogRead (A1);

//     // int direction= 2;

//     // if (X>900) {direction== 0;}
//     // if (X>100) {direction== 1;}
//     // if (Y>900) {direction== 2;}
//     // if (Y>100) {direction== 3;}

//     int direction = random(0, 4);
//     int x = xx[headIdx];
//     int y = yy[headIdx];
//     bool doStep = 1;

//     if (direction == 0) {
//         x += 1;
//     }

//     else if (direction == 1) {
//         x -= 1;
//     }

//     else if (direction == 2) {
//         y += 1;
//     }

//     else {
//         y -= 1;
//     }

//     if (x < 0 || x > 7 || y < 0 || y > 7) {
//         doStep = 0;
//     }

//     for (int scan = 0; scan < 5; scan++) {
//         if (x == xx[scan] && y == yy[scan]) {
//             doStep = 0;
//         }
//     }

//     if (doStep == 1) {
//         headIdx = (headIdx + 1) % 5;
//         xx[headIdx] = x % 8;
//         yy[headIdx] = y % 8;
//         delay(1000);    
//     }
// }