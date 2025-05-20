// Simple autocorrelation pitch detection (fundamental period estimation)
const int micPin = A0;
const int sampleRate = 4000;  // Hz
const int windowSize = 400;
int samples[windowSize];

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Sample
  for (int i = 0; i < windowSize; ++i) {
    samples[i] = analogRead(micPin) - 512; // Subtract DC offset
    delayMicroseconds(1000000UL / sampleRate);
  }

  // Autocorrelation (lags: 10--200, for 20Hz -- 400Hz fundamental)
  int bestLag = 0;
  long bestSum = 0;
  for (int lag = 10; lag < 200; ++lag) {
    long sum = 0;
    for (int i = 0; i < windowSize - lag; ++i) {
      sum += samples[i] * samples[i + lag];
    }
    if (sum > bestSum) {
      bestSum = sum;
      bestLag = lag;
    }
  }
  float freq = sampleRate / float(bestLag);
  Serial.print("Frequency:"); Serial.println(freq);

  delay(100);  // For demonstration (analyze every 0.1 s)
}