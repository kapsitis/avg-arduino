#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

// Kontaktu definīcijas
const int LED_PIN = 8;      // D8: LED gaismiņa
const int BUZZER_PIN = 9;   // D9: Dūcējs
const int SQW_PIN = 2;      // D2 - kontakts, kas saņem kvadrātviļņa ievadi no RTC

volatile bool toggleState = false; // Stāvoklis pārslēgsies ik pēc 0.5s

void setup() {

  Serial.begin(9600);
  // Kontakti, kuri ieslēdz LED un dūcēju
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // D2 kontakts ir gatavs saņemt ievadi no pulkstenīša
  pinMode(SQW_PIN, INPUT);

  // Ieslēdz I2C saziņu un RTC (pulkstenīša moduli)
  Wire.begin();
  rtc.begin();

  // RTC laiku uzstāda tikai vienreiz
  if (!rtc.isrunning()) {
    // Ja pulkstenītim nebija uzstādīts laiks, uzstāda kaut ko
    rtc.adjust(DateTime(2025, 4, 29, 19, 40, 0));
  }
  // Once set, comment out the above two lines to avoid resetting clock every upload

  // Palūdz pulksteņa SQ kontaktam veidot 1Hz izvadi
  rtc.writeSqwPinMode(DS1307_SquareWave1HZ);

  // Sūta pārtraukumu tad, ja kvadrātvilnis ir augošs (reizi sekundē)
  attachInterrupt(digitalPinToInterrupt(SQW_PIN), sqwISR, RISING);
}

void loop() {
  Serial.println("ABC");
  static unsigned long lastMillis = 0;
  static bool ledBuzzerState = false;

  unsigned long currentMillis = millis();

  // Pārbauda, vai "toggleState" ir ieslēgts (katras sekundes sākumā)
  if (toggleState && !ledBuzzerState) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 440);    
    lastMillis = currentMillis;
    ledBuzzerState = true;
  }

  // Izslēdz LED gaismiņu un dūcēju pēc 0.5s
  if (ledBuzzerState && (currentMillis - lastMillis >= 500)) {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);   
    ledBuzzerState = false;
    toggleState = false; // Reset until next interrupt
  }

  // Drukā pašreizējo laiku uz seriālā porta
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
}

// Apstrādā SQ ievades pulsa pārtraukumu
void sqwISR() {
  toggleState = true;
}