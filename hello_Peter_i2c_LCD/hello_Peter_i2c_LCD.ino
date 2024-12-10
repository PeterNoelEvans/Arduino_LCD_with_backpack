#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F depending on your module
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LED_PIN = 2; // Set to the correct GPIO pin for your board

void setup() {
  Serial.begin(9600);        // Initialize Serial communication at 9600 baud rate
  Serial.print("Hi");
  lcd.init();                // Initialize the LCD
  lcd.backlight();           // Turn on the backlight
  lcd.print("hello, Peter!");// Display a message on the LCD
  Serial.println("LCD initialized!");

  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  // Blink the LED
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(500);                  // Wait 500 milliseconds
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  delay(500);                  // Wait 500 milliseconds

  // Update LCD
  lcd.setCursor(0, 1);          // Set cursor to column 0, row 1
  lcd.print(millis() / 1000);   // Print seconds since reset

  // Print to Serial Monitor
  Serial.println(millis() / 1000);
}
