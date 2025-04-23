// Mazā, sirmā kumeliņā
// Jāj pa ceļu pasaciņa.
// Ātri, ātri steidzas viņa,
// Rokā zelta pātadziņa.
// Jāj un jāj un neapstājas,
// Zemes virsū nav tai mājas.
// Līdz ko jaukie sapņi beidzas,
// Viņai projām jāaizsteidzas.


#include <Wire.h>

#define I2C_ADDR 0x70   // Replace if your device uses a different address

// *** 14-segment font table for space and uppercase A-Z (from Adafruit) ***

const uint16_t font14seg[] = {
  0b0000000000000000, // [0] space
  0b0000000000000000, // [1] placehold for !
  // ASCII 'A' to 'Z': index = letter-'A'+2
  0b0000000011110111, // [2] 'A'
  0b0000111111001001, // [3] 'B'
  0b0000000000111001, // [4] 'C'
  0b0000111011001001, // [5] 'D'
  0b0000000011111001, // [6] 'E'
  0b0000000011110001, // [7] 'F'
  0b0000000010111101, // [8] 'G'
  0b0000000011110110, // [9] 'H'

  0b0001001000001001, // [10] 'I'
  0b0000000000011110, // [11] 'J'
  0b0011000011100000, // [12] 'K'
  0b0000000000111000, // [13] 'L'
  0b0000010100110110, // [14] 'M'
  0b0010001010110110, // [15] 'N'
  0b0000000000111111, // [16] 'O'
  0b0000000011110011, // [17] 'P'
  0b0010000000111111, // [18] 'Q'
  0b0010000011110011, // [19] 'R'
  0b0000000011101101, // [20] 'S'
  0b0000111000000001, // [21] 'T'
  0b0000000000111110, // [22] 'U'
  0b0011000000110000, // [23] 'V'
  0b0010100000110110, // [24] 'W'
  0b0011101010000000, // [25] 'X'
  0b0001010100000000, // [26] 'Y'
  0b0000110000001001  // [27] 'Z'
};

// Get segment pattern for char c (supports 'A'-'Z' and space only)
uint16_t charTo14Seg(char c) {
  if (c == ' ') return font14seg[0];
  if (c >= 'A' && c <= 'Z') return font14seg[c - 'A' + 2];
  return 0;
}

 char message[] = " MAZAA SIRMAA KUMELINAA JAAJ PA CELJU PASACINA... ";
//  char message[] = " ABCDEFGH ABCDEFGH ABCDEFGHJ PA CELJU PASACINA... ";
uint8_t msgLen = sizeof(message)-1; // exclude null terminator

void setup() {
  Wire.begin();
  delay(50);

  Wire.beginTransmission(I2C_ADDR); Wire.write(0x21); Wire.endTransmission();
  Wire.beginTransmission(I2C_ADDR); Wire.write(0x81); Wire.endTransmission();
  Wire.beginTransmission(I2C_ADDR); Wire.write(0xEF); Wire.endTransmission();
}

// Show 4 chars given a pointer to their array
void show4(const char* chars) {
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00); // Start address
  for (uint8_t i = 0; i < 4; i++) {
    uint16_t seg = charTo14Seg(chars[i]);
    Wire.write(seg & 0xFF);       // low byte
    Wire.write((seg >> 8) & 0xFF); // high byte
  }
  Wire.endTransmission();
}

void loop() {
  static uint8_t scroll = 0;
  char window[4];
  for (int i=0; i<4; i++) {
    uint8_t idx = (scroll+i) % msgLen;
    char c = message[idx];
    if (c >= 'a' && c <= 'z') c -= ('a'-'A'); // force uppercase
    window[i] = c;
  }
  show4(window);
  scroll++;
  if (scroll >= msgLen) scroll = 0;
  delay(400);
}