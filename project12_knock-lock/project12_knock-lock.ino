// Import the Servo library
#include <Servo.h>
Servo myServo;

// Create constants for I/Os
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

// Create variables to hold the values from your switch and piezo
int knockVal;
int switchVal; 

// Set thresholds for knock maximum and minimum levels using constants
const int quietKnock = 10;
const int loudKnock = 100;

// Create variables for the lock state and number of knocks
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // Set the direction of the digital pins and initialize servo objects and serial port
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);

  // Unlock
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");  

}

void loop() {
  // Check the switch
  if(locked == false){
    switchVal = digitalRead(switchPin);
    
    // Lock it up!
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  
  // Checking the knock sensor
  if(locked == true){
    knockVal = analogRead(piezo);
    
    // Counting only valid knocks
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    } 

    // Unlock
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;
    }
  } 
}

// Defining a function to check knock safety
boolean checkForKnock(int value){
  
  // Check validity of knock
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true; // Return command states outcome of function, terminates functions, and returns to main program
  }
  
  // Indicating invalid knock; function returns false
  else{
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
