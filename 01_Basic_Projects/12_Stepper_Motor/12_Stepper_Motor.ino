/****************************************************************************
 * File:        12_Stepper_Motor.ino
 * Project:     Stepper Motor (28BYJ-48 + ULN2003)
 * Author:      AYNOP Enterprises
 * Created:     20-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Beginner-friendly project to control a 28BYJ-48 stepper motor using
 *   the ULN2003 driver board. The motor will:
 *     - Rotate one full revolution clockwise
 *     - Pause
 *     - Rotate one full revolution counter-clockwise
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

#include <Stepper.h>

// Stepper motor details
#define STEPS_PER_REV 2048  // 28BYJ-48 ≈ 2048 steps per revolution (full-step)

// ULN2003 driver inputs connected to Arduino pins
#define IN1_PIN 8   // ULN2003 IN1 → Arduino pin 8
#define IN2_PIN 9   // ULN2003 IN2 → Arduino pin 9
#define IN3_PIN 10  // ULN2003 IN3 → Arduino pin 10
#define IN4_PIN 11  // ULN2003 IN4 → Arduino pin 11

// Create Stepper object (note pin order: IN1, IN3, IN2, IN4)
Stepper myStepper(STEPS_PER_REV, IN1_PIN, IN3_PIN, IN2_PIN, IN4_PIN);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(10); // Set speed (RPM) 
  delay(2000);
  Serial.println("AYNOP: Stepper Motor Demo");
}

void loop() {
  // Rotate one full revolution clockwise
  Serial.println("Rotating clockwise...");
  myStepper.step(STEPS_PER_REV);
  delay(1000);

  // Rotate one full revolution counter-clockwise
  Serial.println("Rotating  anti clockwise...");
  myStepper.step(-STEPS_PER_REV);
  delay(2000);
}

