#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  displayMorseCode("PARIS");
  delay(7000);  // Delay between word repetition (7 units of dot length)
}

void displayMorseCode(String text) {
  String morseAlphabet[] = {
    ".-", "-...", "-.-.", "-..", ".",    // A, B, C, D, E
    "..-.", "--.", "....", "..", ".---", // F, G, H, I, J
    "-.-", ".-..", "--", "-.", "---",    // K, L, M, N, O
    ".--.", "--.-", ".-.", "...", "-",   // P, Q, R, S, T
    "..-", "...-", ".--", "-..-", "-.--",// U, V, W, X, Y
    "--.."                              // Z
  };

    
  text.toUpperCase();
  for (int i = 0; i < text.length(); i++) {
    char c = text.charAt(i);
    if (c >= 'A' && c <= 'Z') {
      String morseCode = morseAlphabet[c - 'A'];
      for (int j = 0; j < morseCode.length(); j++) {
        if (morseCode[j] == '.') {
          signalDot();
        } else if (morseCode[j] == '-') {
          signalDash();
        }
        delay(200); // Pause between dot/dash in the same character (1 unit)
      }
      delay(600); // Pause between characters (3 units)
    }
  }
}

void signalDot() {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
}

void signalDash() {
  digitalWrite(LED_PIN, HIGH);
  delay(600);
  digitalWrite(LED_PIN, LOW);
}

