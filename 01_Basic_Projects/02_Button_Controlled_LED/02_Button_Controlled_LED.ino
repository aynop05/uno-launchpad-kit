/********************************************************************************************
 * File:        02_Button_Controlled_LED.ino
 * Project:     Button Controlled LED
 * Author:      AYNOP Enterprises
 * Created:     18-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Demonstrates controlling an LED using a push button connected to a digital input pin. 
 *   The button is wired with an external pull-down resistor to ensure a stable LOW state. 
 *   Helps beginners understand the basics of digital input (button press) and output (LED).
 *
 * Revision History:
 *   v1.0 - Initial release
 *
 * License:
 *   This content (source code and documentation) is licensed under 
 *   Creative Commons BY-NC-SA 4.0. © 2025 AYNOP. You may use, modify, 
 *   and share for personal and educational purposes only. Commercial 
 *   use or redistribution without prior written permission is strictly 
 *   prohibited. Refer to the LICENSE file for complete details.
 ********************************************************************************************/

// Pin configuration
const int buttonPin = 2;   // Pushbutton connected to digital pin 2
const int ledPin    = 13;  // LED connected to digital pin 13 (onboard LED)

// Variable to store the button state
int buttonState = 0;

void setup() {
  // Set LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);

  // Set button pin as INPUT (external pull-down resistor required)
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // Check if the pushbutton is pressed
  if (buttonState == HIGH) {
    // Turn LED ON when button is pressed
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn LED OFF when button is released
    digitalWrite(ledPin, LOW);
  }
}
