// Import the library
#include <Servo.h>

//Creating the servo object
Servo myServo;

// Declare variables
int const potPin = A0;
int potVal;
int angle;

void setup() {
  // Associate the servo object with the Arduino pin
  myServo.attach(9);

  // Initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Map the potentiometer value to the servo values
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  // Rotate the servo
  myServo.write(angle);
  delay(15); // Delay so the servo has time to move its new position
}
