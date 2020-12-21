// Import the CapacitiveSensor library
#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2); // pin 4 sends to foil; pin 2 sense pin

// Set threshold for sensing to turn lamp on
int threshold = 1000;
const int ledPin = 12; // LED pin

void setup() {
  // Open serial connection
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Sense touch
  long sensorValue = capSensor.capacitiveSensor(30); // Create variable to hold value
  Serial.println(sensorValue); // Print value

  // Control lamp
  if(sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}
