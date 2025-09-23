/****************************************************************************
 * File:        18_Joystick_Module.ino
 * Project:     Joystick Module (Basic Reading)
 * Author:      AYNOP Enterprises
 * Created:     29-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima
 * IDE:         Arduino IDE 2.0 or later
 *
 * Description:
 *   This project demonstrates how to use a joystick module with the
 *   Arduino UNO R4 Minima. The joystick has two potentiometers
 *   (for X and Y axes) and a push button (when pressed).
 *
 *   The sketch reads X, Y values using analog inputs and the button
 *   state using a digital input, then prints them to the Serial Monitor.
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
 ****************************************************************************/

// Pin definitions
#define VRX_PIN A1    // Joystick X-axis
#define VRY_PIN A0    // Joystick Y-axis
#define SW_PIN  9     // Joystick button

void setup() {
  Serial.begin(9600);      // Start Serial Monitor
  pinMode(SW_PIN, INPUT_PULLUP); // Use internal pull-up for button
  delay(2000);
  Serial.println("AYNOP: Joystick Started");
}

void loop() {
  int xValue = analogRead(VRX_PIN);   // Read X-axis (0–1023)
  int yValue = analogRead(VRY_PIN);   // Read Y-axis (0–1023)
  int buttonState = digitalRead(SW_PIN); // Read button (LOW = pressed)

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  if (buttonState == LOW) {
    Serial.println("PRESSED");
  } else {
    Serial.println("RELEASED");
  }

  delay(300); // Small delay for readability
}

