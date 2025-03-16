void setup() {
  // uzstāda digitālo kontaktu LED_BUILTIN (jeb 13 adatiņu) kā izvadi.
  pinMode(LED_BUILTIN, OUTPUT);
}

// Šis cikls arvien atkārtojas, kamēr Arduino ir ieslēgts
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // ieslēdz LED, uzstādot spriegumu HIGH uz 13. kontakta,
  delay(1000);                     // gaida 1 sekundi,
  digitalWrite(LED_BUILTIN, LOW);  // izslēdz LED, uzstādot spriegumu LOW uz 13.kontakta,
  delay(1000);                     // gaida 1 sekundi.
}
