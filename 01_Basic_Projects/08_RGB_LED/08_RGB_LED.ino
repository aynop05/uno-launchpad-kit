/****************************************************************************
 * File:        08_RGB_LED.ino
 * Project:     RGB LED (4-Pin, Common Cathode with Single Resistor)
 * Author:      AYNOP Enterprises
 * Created:     19-08-2025
 * Version:     1.2
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Demonstrates basic control of a 4-pin common-cathode RGB LED 
 *   using Arduino. The LED has 4 pins: one common cathode (GND), 
 *   and separate anode pins for Red, Green, and Blue.
 *
 *   In this setup:
 *     - The **common cathode (GND)** pin is connected to Arduino GND 
 *       **through a single 220Ω–330Ω resistor**.
 *     - The three anode pins (R, G, B) are connected directly to 
 *       Arduino digital pins.
 *
 *   The sketch cycles through three basic colors: Red, Green, and Blue.
 *
 * Revision History:
 *   v1.0 - First public release 
 *
 * License:
 *   This content (source code and documentation) is licensed under 
 *   Creative Commons BY-NC-SA 4.0. © 2025 AYNOP. You may use, modify, 
 *   and share for personal and educational purposes only. Commercial 
 *   use or redistribution without prior written permission is strictly 
 *   prohibited. Refer to the LICENSE file for complete details.
 ****************************************************************************/

// Define Arduino pin connections for RGB LED
const int redPin   = 13;  // Connect to Red anode pin
const int greenPin = 12;  // Connect to Green anode pin
const int bluePin  = 11;  // Connect to Blue anode pin
// Common Cathode pin → Arduino GND through a single resistor

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Show Red
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Show Green
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Show Blue
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(1000);
}
