// Name your constants and variables
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup() {
  // Declasre the pins' direction
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  // Read the input
  switchState = digitalRead(switchPin);
  
  // Pull the output high if pressed
  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}
