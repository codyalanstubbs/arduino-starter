// Declare a named constant
const int switchPin = 8;

// Create a variable to hold the time
unsigned long previousTime = 0;

// Name variables for the inputs and outputs
int switchState = 0;
int prevSwitchState = 0;
int led = 2;

// Declare a variable describing the interval between events
long interval = 6000;

void setup() {
  // Set the direction of your digital pins
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  // Check the time since the program started running
  unsigned long currentTime = millis();

 // Evaluate the amount of time that has passed since the previous loop()
 if(currentTime - previousTime > interval) {
  previousTime = currentTime;

  // Turn on an LED prepare for the next one
  digitalWrite(led, HIGH);
  led++;

  // Check to see if all lights are on
  if(led == 7) {
    }
 }
 // Read the value of the switch
 switchState = digitalRead(switchPin);

 // Read the variabes to their defaults if necessary
 if(switchState != prevSwitchState){
  for(int x = 2; x < 8; x++){
    digitalWrite(x, LOW);
  }

  led = 2;
  previousTime = currentTime;
 }

 // Set the current state to the previous state
 prevSwitchState = switchState;
}
