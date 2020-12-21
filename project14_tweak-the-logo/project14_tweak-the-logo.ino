 void setup() {
  // Open serial connection
  Serial.begin(9600);

}

void loop() {
  // Send the sensor value
  Serial.write(analogRead(A0)/4);
  delay(1);
}
