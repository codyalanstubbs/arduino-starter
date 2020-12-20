// Create variables for calibrating the sensor
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// Name a constant for your calibration indicator
const int ledPin = 13;

void setup() {
  
  // Set the digital pin direction and turn it high
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Use a while() loop for calibration
  while (millis() < 5000) {
    // Compare sensor values for calibration
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  // Indicate calibrations has finished
  digitalWrite(ledPin, LOW);

  // Initialize a serial port 
  Serial.begin(9600);
  
}

void loop() {
  // Read and store the sensor value
  sensorValue = analogRead(A0);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  // Map the sensor value to a frequency
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.print("Pitch Value: ");
  Serial.println(pitch);

  // Play the frequency
  tone(8, pitch, 20);

  // Delay for 10 ms to allow sound time to play
  delay(10);
  
}
