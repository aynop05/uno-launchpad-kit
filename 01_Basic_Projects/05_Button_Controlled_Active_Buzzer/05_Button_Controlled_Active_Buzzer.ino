/********************************************************************************************
 * File:        05_Button_Controlled_Active_Buzzer.ino
 * Project:     Button Controlled Active Buzzer
 * Author:      AYNOP Enterprises
 * Created:     18-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.0 or later
 *
 * Description:
 *   In this project, a pushbutton controls an active buzzer. When the button is pressed,
 *   the buzzer produces a sound. When the button is released, the buzzer is silent.
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
const int buttonPin  = 2;   // Pushbutton connected to digital pin 2
const int buzzerPin  = 8;   // Active buzzer connected to digital pin 8

// Variable to store the button state
int buttonState = 0;

void setup() {
  // Configure pins
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);  // External pull-down resistor required
}

void loop() {
  // Read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Button pressed → turn ON buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Button released → turn OFF buzzer
    digitalWrite(buzzerPin, LOW);
  }
}