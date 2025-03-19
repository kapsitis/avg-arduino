void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // uzstāda 13.kontaktu kā izvadi
}

void loop() { // Šis cikls atkārtojas, kamēr Arduino ir ieslēgts
  digitalWrite(LED_BUILTIN, HIGH); // ieslēdz LED ar spriegumu HIGH uz 13. kontakta
  delay(1000);                     // gaida 1 sekundi,
  digitalWrite(LED_BUILTIN, LOW);  // izslēdz LED ar spriegumu LOW uz 13.kontakta
  delay(1000);                     // gaida 1 sekundi.
}
