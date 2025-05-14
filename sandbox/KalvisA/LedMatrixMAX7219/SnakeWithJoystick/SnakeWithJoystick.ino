#include <LedControl.h>

// LED matrix pins: DIN=11, CLK=13, CS=10, 1 device
LedControl lc = LedControl(11, 13, 10, 1);

// Snake body (stores head and last 4 positions)
int xx[5] = {0, 1, 2, 3, 4};
int yy[5] = {0, 0, 0, 0, 0};
int headIdx = 4;

// Joystick settings
#define JOY_X A0
#define JOY_Y A1
#define DEADZONE 100
#define CENTER   512

unsigned long lastMoveTime = 0;
const unsigned long interval = 200; // ms per step

// Directions: 0=right, 1=left, 2=up, 3=down, -1=stopped
int lastDirection = -1;

void setup() {
  Serial.begin(9600); 
  lc.shutdown(0, false);    // Wake up MAX7219
  lc.setIntensity(0, 8);    // Brightness 0-15
  lc.clearDisplay(0);       // Clear display  
  randomSeed(analogRead(0));
}

void loop() {
  unsigned long now = millis();
  if (now - lastMoveTime < interval) return;



  lastMoveTime = now;

  // Read Joystick
  int X = analogRead(JOY_X);
  int Y = analogRead(JOY_Y);


    Serial.print(X);
    Serial.print(",");
    Serial.println(Y);

  int direction = -1;

  if (X > CENTER + DEADZONE) direction = 0; // right
  else if (X < CENTER - DEADZONE) direction = 1; // left
  else if (Y > CENTER + DEADZONE) direction = 3; // down (Y increases downward on Arduino joystick)
  else if (Y < CENTER - DEADZONE) direction = 2; // up

  // Only update direction if not reversal and direction valid
  if (
    direction != -1
    && !((lastDirection == 0 && direction == 1) ||
         (lastDirection == 1 && direction == 0) ||
         (lastDirection == 2 && direction == 3) ||
         (lastDirection == 3 && direction == 2))
  ) {
    lastDirection = direction;
  }

  // Don't move if stopped (stick centered)
  if (lastDirection == -1) {
    drawSnake();
    return;
  }

  // Calculate next head position
  int x = xx[headIdx];
  int y = yy[headIdx];

  if      (lastDirection == 0) x += 1;
  else if (lastDirection == 1) x -= 1;
  else if (lastDirection == 2) y -= 1;
  else if (lastDirection == 3) y += 1;

  bool moveOk = true;
  // Check bounds
  if (x < 0 || x > 7 || y < 0 || y > 7) moveOk = false;
  // Check for collision with body
  for (int i = 0; i < 5; i++) {
    if (x == xx[i] && y == yy[i]) moveOk = false;
  }

  if (moveOk) {
    headIdx = (headIdx + 1) % 5;
    xx[headIdx] = x;
    yy[headIdx] = y;
  } else {
    lastDirection = -1; // If hit wall or self, stop the snake
  }
  drawSnake();
}

// Draw the current snake positions to the display
void drawSnake() {
  for (int row = 0; row < 8; row++) {
    byte pattern = 0;
    for (int i = 0; i < 5; i++) {
      if (yy[i] == row) pattern |= (1 << xx[i]);
    }
    lc.setRow(0, row, pattern);
  }
}
