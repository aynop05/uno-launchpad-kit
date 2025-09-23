/********************************************************************************************
 * File:        01_Led_Blink_External.ino
 * Project:     External LED Blink
 * Author:      AYNOP Enterprises
 * Created:     12-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Simple example to toggle an external LED connected to a defined digital output pin at a fixed interval.
 *   Demonstrates basic digital output functionality on the UNO R4 Minima.
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

#define LED_PIN 13              // Digital pin connected to external LED
#define BLINK_INTERVAL_MS 1000  // Blink interval in milliseconds

void setup() {
  // Initialize the external LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_INTERVAL_MS);

  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  delay(BLINK_INTERVAL_MS);
}
