/****************************************************************************
 * File:        07_Single_Digit_7Segment_Display.ino
 * Project:     Single-Digit 7-Segment Display
 * Author:      AYNOP Enterprises
 * Created:     19-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Demonstrates how to drive a single-digit 7-segment common-cathode 
 *   display using Arduino. A single current-limiting resistor is placed 
 *   on the common cathode pin for simplicity.
 *
 *   The sketch sequentially displays digits 0 through 9 with a 1-second delay.
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

// Define Arduino pin connections for each 7-segment LED segment
const int segC_pin = 2;
const int segD_pin = 3;
const int segE_pin = 4;
const int segG_pin = 5;
const int segF_pin = 6;
const int segA_pin = 7;
const int segB_pin = 8;


// Digit patterns for 0–9 (Common Cathode: HIGH = ON, LOW = OFF)
byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  pinMode(segA_pin, OUTPUT);
  pinMode(segB_pin, OUTPUT);
  pinMode(segC_pin, OUTPUT);
  pinMode(segD_pin, OUTPUT);
  pinMode(segE_pin, OUTPUT);
  pinMode(segF_pin, OUTPUT);
  pinMode(segG_pin, OUTPUT);
}

void displayDigit(int num) {
  digitalWrite(segA_pin, digits[num][0]);
  digitalWrite(segB_pin, digits[num][1]);
  digitalWrite(segC_pin, digits[num][2]);
  digitalWrite(segD_pin, digits[num][3]);
  digitalWrite(segE_pin, digits[num][4]);
  digitalWrite(segF_pin, digits[num][5]);
  digitalWrite(segG_pin, digits[num][6]);
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);
    delay(1000);  // Show each digit for 1 second
  }
}
