 // Import the set up for the serial object
 import processing.serial.*;
 Serial myPort;
 
 // Create an object for the image
 PImage logo;
 
 // Create variable to store the background color
 int bgcolor = 0;
 
 void setup() {
   
   // Setting the color mode
   size(1, 1);
   surface.setResizable(true);
   colorMode(HSB, 255);
   
   // Loading the image
   logo = loadImage("http://arduino.cc/arduino_logo.png");
   surface.setSize(logo.width, logo.height);
   
   // Printing available serial ports
   println("Available serial ports:");
   println((Object[])Serial.list());
   
   // Creating the serial object
   myPort = new Serial(this, Serial.list()[1], 9600);
 }
 
 void draw() {
   // Reading Arduino data from te serial port
   if (myPort.available() > 0) {
     bgcolor = myPort.read();
     println(bgcolor);
   }
   
   // Setting the image background and displaying the image
   background(bgcolor, 255, 255);
   image(logo, 0, 0);
 }
