// Goertzel tone detection at 220Hz
const int N = 400;            // number of samples
const float TARGET_FREQ = 220.0; // Hz
const float SAMPLE_RATE = 4000.0;
const int micPin = A0;
int samples[N];

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Acquire samples
  for(int i=0; i<N; i++) {
    samples[i] = analogRead(micPin) - 512;
    delayMicroseconds(1000000UL/SAMPLE_RATE);
  }
  
  // Goertzel
  float s_prev = 0, s_prev2 = 0;
  float normalizedFreq = TARGET_FREQ / SAMPLE_RATE;
  float coeff = 2 * cos(2 * PI * normalizedFreq);

  for(int i=0; i<N; i++) {
    float s = samples[i] + coeff * s_prev - s_prev2;
    s_prev2 = s_prev;
    s_prev = s;
  }
  float power = s_prev2 * s_prev2 + s_prev * s_prev - coeff * s_prev * s_prev2;
  Serial.print("220Hz Power: ");
  Serial.println(power);

  delay(100);
}