#ifndef Adafruit_LEDBackpack_h
#define Adafruit_LEDBackpack_h

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_I2CDevice.h>

#include "Adafruit_GFX.h"

#define LED_ON 1  
#define LED_OFF 0 

#define LED_RED 1    
#define LED_YELLOW 2 
#define LED_GREEN 3  

#define HT16K33_BLINK_CMD 0x80       
#define HT16K33_BLINK_DISPLAYON 0x01 
#define HT16K33_BLINK_OFF 0          
#define HT16K33_BLINK_2HZ 1          
#define HT16K33_BLINK_1HZ 2          
#define HT16K33_BLINK_HALFHZ 3       

#define HT16K33_CMD_BRIGHTNESS 0xE0 

#define SEVENSEG_DIGITS 5 

/*
Segment names for 14-segment alphanumeric displays.
See https://learn.adafruit.com/14-segment-alpha-numeric-led-featherwing/usage

    -------A-------
    |\     |     /|
    | \    J    / |
    |   H  |  K   |
    F    \ | /    B
    |     \|/     |
    |--G1--|--G2--|
    |     /|\     |
    E    / | \    C
    |   L  |   N  |
    | /    M    \ |
    |/     |     \|
    -------D-------  DP
*/

#define ALPHANUM_SEG_A 0b0000000000000001  
#define ALPHANUM_SEG_B 0b0000000000000010  
#define ALPHANUM_SEG_C 0b0000000000000100  
#define ALPHANUM_SEG_D 0b0000000000001000  
#define ALPHANUM_SEG_E 0b0000000000010000  
#define ALPHANUM_SEG_F 0b0000000000100000  
#define ALPHANUM_SEG_G1 0b0000000001000000 
#define ALPHANUM_SEG_G2 0b0000000010000000 
#define ALPHANUM_SEG_H 0b0000000100000000  
#define ALPHANUM_SEG_J 0b0000001000000000  
#define ALPHANUM_SEG_K 0b0000010000000000  
#define ALPHANUM_SEG_L 0b0000100000000000  
#define ALPHANUM_SEG_M 0b0001000000000000  
#define ALPHANUM_SEG_N 0b0010000000000000  
#define ALPHANUM_SEG_DP 0b0100000000000000 


class Adafruit_LEDBackpack {
public:
  Adafruit_LEDBackpack(void);

  bool begin(uint8_t _addr = 0x70, TwoWire *theWire = &Wire);

  void setDisplayState(bool state);

  void setBrightness(uint8_t b);

  void blinkRate(uint8_t b);

  void writeDisplay(void);

  void clear(void);

  uint16_t displaybuffer[8]; 

protected:
  Adafruit_I2CDevice *i2c_dev = NULL; 
};

class Adafruit_24bargraph : public Adafruit_LEDBackpack {
public:
  Adafruit_24bargraph(void);

  void setBar(uint8_t bar, uint8_t color);
};

class Adafruit_8x16matrix : public Adafruit_LEDBackpack, public Adafruit_GFX {
public:
  Adafruit_8x16matrix(void);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

class Adafruit_8x16minimatrix : public Adafruit_LEDBackpack,
                                public Adafruit_GFX {
public:
  Adafruit_8x16minimatrix(void);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

class Adafruit_8x8matrix : public Adafruit_LEDBackpack, public Adafruit_GFX {
public:
  Adafruit_8x8matrix(void);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

class Adafruit_BicolorMatrix : public Adafruit_LEDBackpack,
                               public Adafruit_GFX {
public:
  Adafruit_BicolorMatrix(void);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

#define RAW_BITS 0 


class Adafruit_7segment : public Adafruit_LEDBackpack {
public:
  Adafruit_7segment(void);

  size_t write(char c);

  size_t write(const char *buffer, size_t size);

  void print(char c);

  void print(unsigned char b, int base = RAW_BITS);

  void print(int n, int base = DEC);

  void print(unsigned int n, int base = DEC);

  void print(long n, int base = DEC);

  void print(unsigned long n, int base = DEC);

  void print(double n, int digits = 2);

  void print(const String &c);

  void print(const char c[]);

  void println(char c);

  void println(unsigned char b, int base = RAW_BITS);

  void println(int n, int base = DEC);

  void println(unsigned int n, int base = DEC);

  void println(long n, int base = DEC);

  void println(unsigned long n, int base = DEC);

  void println(double n, int digits = 2);

  void println(const String &c);

  void println(const char c[]);

  void println(void);

  void writeDigitRaw(uint8_t x, uint8_t bitmask);

  void writeDigitNum(uint8_t x, uint8_t num, bool dot = false);

  void writeDigitAscii(uint8_t x, uint8_t c, bool dot = false);

  void drawColon(bool state);

  void printNumber(long n, uint8_t base = 2);

  void printFloat(double n, uint8_t fracDigits = 2, uint8_t base = DEC);

  void printError(void);

  void writeColon(void);

private:
  uint8_t position; 
};

class Adafruit_AlphaNum4 : public Adafruit_LEDBackpack {
public:
  Adafruit_AlphaNum4(void);

  void writeDigitRaw(uint8_t n, uint16_t bitmask);

  void writeDigitAscii(uint8_t n, uint8_t ascii, bool dot = false);
};

#endif // Adafruit_LEDBackpack_h