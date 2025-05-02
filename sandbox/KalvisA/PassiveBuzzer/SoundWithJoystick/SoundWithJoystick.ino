// KY-023 kursorsviras (Joystick-a) modulis
const int pinSW = 2;     // Digitāls kontakts pogai
const int pinVRX = A0;   // Analogs kontakts X-koordinātei
const int pinVRY = A1;   // Analogs kontakts Y-koordinātei

int xValue = 512;      // nolasītā X vērtība (512 - neitrāla kursorsviras pozīcija)
int yValue = 512;      // nolasītā Y vērtība (512 - neitrāla kursorsviras pozīcija)
int swValue = 0;       // pogas stāvoklis (1 = nospiesta)

int BUZZER_PIN = 8;

int freq = 1000;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  pinMode(pinSW, INPUT_PULLUP); // Enable internal pull-up resistor for the switch
}

void loop() {
  // Read all values
  xValue = analogRead(pinVRX);
  yValue = analogRead(pinVRY);
  Serial.print(yValue);
  Serial.print(",");
  Serial.println(freq);

  int newFreq = 2*yValue+100;

  // Pakāpeniski palielina vai samazina frekvenci, lai tuvotos lietotāja vēlmei
  if (newFreq < freq) {
    freq--;
  }
  if (newFreq > freq) {
    freq++;
  }

  tone(BUZZER_PIN, freq);
  // Notur frekvenci 20 milisekundes pirms mainīšanas
  delay(20);
}