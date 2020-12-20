// Set up an array with 6 integers
int buttons[6];

// Create an array of frequencies 
int notes[] = {262, 294, 330, 349};

void setup() {
  // Give the first element of the array the value 2
  buttons[0] = 2;
  
  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value and send it to the serial monitor
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // Use an if()...else statement to determine what not to play
  if(keyVal == 1023){
    tone(8, notes[0]);
  }
  // Play the notes that correspond to the analog value
  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 5015){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
  // Stop playing the tone when nothing is pressed
  else{
    noTone(8);
  }
}
