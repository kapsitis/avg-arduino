#include <Wire.h>
#include <HT16K33.h>

// Create display object with I2C address 0x70
HT16K33 segDisplay(0x70);

void setup() {
  Wire.begin();
  segDisplay.begin();
  segDisplay.displayOn();
  segDisplay.setBrightness(15);  // 0-15
}

void loop() {
  for (int digit = 0; digit < 4; digit++) {
    // Clear display by writing 0 to all digits
    segDisplay.displayClear();
    
    // Display '8' on the current digit
    // This library uses a single function to display a 4-digit hex number
    // So we need to construct a number with '8' in the desired position
    uint16_t number = 0;
    switch(digit) {
      case 0: number = 0x0008; break;  // 8 in rightmost digit
      case 1: number = 0x0080; break;  // 8 in second digit
      case 2: number = 0x0800; break;  // 8 in third digit
      case 3: number = 0x8000; break;  // 8 in leftmost digit
    }
    segDisplay.displayHex(number);
    
    delay(1000);
  }
}



// #include <Wire.h>
// #include <HT16K33.h>

// // Create display object with I2C address 0x70
// HT16K33 segDisplay(0x70);  // Note the constructor now includes the address

// void setup() {
//   Wire.begin();
//   segDisplay.begin();
//   segDisplay.displayOn();
//   segDisplay.setBrightness(15);  // 0-15
// }

// void loop() {
//   for (int digit = 0; digit < 4; digit++) {
//     segDisplay.clear();
    
//     // Display '8' on the current digit
//     // For this library, we need to specify the position and value
//     // Positions are typically 0-3 for a 4-digit display
//     segDisplay.displayHex(digit, 8);  // digit position, value
    
//     delay(1000);
//   }
// }