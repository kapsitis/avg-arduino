#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    float distanceCm;

    // Signāla sūtīšanas kontaktu uz brīdi izslēdz
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Sūta 10 mikrosekundes garu HIGH (5V) uz signāla sūtīšanas kontaktu
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Nolasa atbildes kontaktu (rezultāts "duration" ir mikrosekundes)
    duration = pulseIn(ECHO_PIN, HIGH);

    // Pārveido "duration" no mikrosekundēm uz centimetriem
    distanceCm = duration * 0.034 / 2;

    Serial.print("Distance:");
    Serial.println(distanceCm);

    delay(500);
}