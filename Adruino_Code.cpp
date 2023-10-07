#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD object

int counter = 0; // Initialize a counter variable
const int buttonPin = 7; // Define the button input pin
const int greenLightPin = 8; // Define the pin for the green light
const int redLightPin = 9; // Define the pin for the red light

void setup() {
  // Set up the I/O pins
  pinMode(buttonPin, INPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(redLightPin, OUTPUT);
  
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("LIFE IS TOO SHO");
  lcd.setCursor(0, 1);
  lcd.print("RT FOR TRAFFIC");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YOU CAN GO:");
}

void loop() {
  // Check if the button is pressed and the counter is less than 8
  if (digitalRead(buttonPin) == LOW && counter < 8) {
    digitalWrite(greenLightPin, HIGH); // Turn on the green light
    delay(400);
    counter++; // Increment the counter
  }
  
  // Display the corresponding number on the 7-segment display based on the counter value
  lcd.setCursor(0, 1);
  lcd.print("          "); // Clear the line
  lcd.setCursor(0, 1);
  lcd.print(counter);
  
  // When the counter reaches 8, indicate the need to stop
  if (counter == 8) {
    digitalWrite(redLightPin, HIGH); // Turn on the red light
    digitalWrite(greenLightPin, LOW); // Turn off the green light
    lcd.setCursor(0, 0);
    lcd.print("PLEASE STOP:");
  }
}
