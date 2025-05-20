const int micPin = A0;
const unsigned int sampleRate = 8000;    // in Hz
const unsigned int samplePeriodUs = 1000000 / sampleRate;
const unsigned int windowMs = 50;        // Window length for frequency measurement (ms)
const unsigned int windowSamples = sampleRate * windowMs / 1000;
const int baseline = 256;                // DC offset (depends on Vdd and MAX9814)

void setup() {
  // Serial.begin(115200);
  Serial.begin(9600);
}

void loop() {
  int prevSample = analogRead(micPin);
  int currSample;
  unsigned long startTime = micros();
  unsigned int zeroCrossings = 0;
  bool wasBelow = (prevSample < baseline);

  // Sample "windowSamples" times in this windowMs window
  for (unsigned int i = 0; i < windowSamples; i++) {
    // Precise timing for the next sample
    while (micros() - startTime < i * samplePeriodUs); // Wait for sample time

    currSample = analogRead(micPin);

    // Detect rising zero crossing
    if (wasBelow && currSample >= baseline) {
      zeroCrossings++;
      wasBelow = false;
    }
    if (currSample < baseline) {
      wasBelow = true;
    }
    // else: was/now above baseline, do nothing
  }
  // Compute frequency (each full cycle has two zero crossings)
  float frequency = (zeroCrossings / 2.0) * (1000.0 / windowMs);

  Serial.print("FrequencyHz:");
  Serial.println(frequency, 2);
  //Serial.println(" Hz");

  delay(100); // Give serial some time
}