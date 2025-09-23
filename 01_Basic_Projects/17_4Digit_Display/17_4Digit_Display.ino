/****************************************************************************
 * File:        17_4Digit_Display.ino
 * Project:     4-Digit Display (TM1637)
 * Author:      AYNOP Enterprises
 * Created:     28-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   This project demonstrates how to use a TM1637-based 4-digit 
 *   7-segment display with the Arduino UNO R4 Minima.
 *   The display will show a counting number that updates every second.
 *
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

#include <TM1637Display.h>

// Pin definitions (as per AYNOP standard)
#define CLK_PIN 3
#define DIO_PIN 2

// Create display object
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  display.setBrightness(5);   // Brightness level (0–7)
  display.clear();            // Clear to avoid stuck after reflash
}

void loop() {
  // Simple counter from 0 to 9999
  for (int number = 0; number <= 9999; number++) {
    display.showNumberDec(number); // Display number
    delay(1000);                   // Update every 1 second
  }
}
