// Set up the LiquidCrystal
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Set constants and variables
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // Print your first line
  lcd.begin(16, 2); // Start the LCD library and tell it how large the screen is
  pinMode(switchPin, INPUT); // Set up the switch pin as an input
  lcd.print("Ask the");
  lcd.setCursor(0, 1); // Move cursor the cursor to proper place: first column second line
  lcd.print("Crystall Ball!");
}

void loop() {
  // Check the switch first and put value in variable
  switchState = digitalRead(switchPin);

  // Choose a random answer
  if (switchState != prevSwitchState) { // Determine if the switch is in a different state than it was previously
    if (switchState == LOW) { // If different than previous and state is LOW, then produce random number
      reply = random(8);  // 8 different numbers so random pulls from 0-7
      lcd.clear(); // Clear screen
      lcd.setCursor(0, 0); // Move cursor back to first row and first column
      lcd.print("The ball says:");
      lcd.setCursor(0, 1); // Move cursor to output

      // Predict the future
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;       
      }
    }
  }
  prevSwitchState = switchState;
}
