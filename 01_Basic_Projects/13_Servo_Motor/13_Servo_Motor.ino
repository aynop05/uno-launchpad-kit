/****************************************************************************
 * File:        13_Servo_Motor.ino
 * Project:     Servo Motor Basics (SG90)
 * Author:      AYNOP Enterprises
 * Created:     20-08-2025
 * Version:     1.0 
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Beginner-friendly project to control a Servo Motor (SG90).
 *   The servo will:
 *     - Move from 0° to 180° gradually
 *     - Pause
 *     - Move back from 180° to 0°
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
 *****************************************************************************/

#include <Servo.h>

// Servo signal pin
#define SERVO_PIN 6   // Servo signal connected to Arduino digital pin 6

Servo myServo;  // Create servo object

void setup() {
  myServo.attach(SERVO_PIN);  // Attach servo to pin
}

void loop() {
  // Sweep from 0° to 180°
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);     // Move servo to 'pos'
    delay(15);              // Small delay for smooth movement
  }

  delay(1000);  // Pause at 180°

  // Sweep back from 180° to 0°
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }

  delay(2000);  // Pause before repeating
}