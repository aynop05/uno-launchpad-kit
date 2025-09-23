/****************************************************************************
 * File:        15_Ultrasonic_Distance_Meter.ino
 * Project:     Ultrasonic Distance Meter using HC-SR04
 * Author:      AYNOP Enterprises
 * Created:     25-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Simple project to measure distance using the HC-SR04 sensor.
 *   The sensor sends an ultrasonic pulse and waits for the echo.
 *   To make results more reliable, we take 3 readings and use the 
 *   first valid one. If all readings fail, we print "No Object".
 *
 * Revision History:
 *   v1.0 - Basic single reading
 *
 * License:
 *   This content (source code and documentation) is licensed under 
 *   Creative Commons BY-NC-SA 4.0. © 2025 AYNOP. You may use, modify, 
 *   and share for personal and educational purposes only. Commercial 
 *   use or redistribution without prior written permission is strictly 
 *   prohibited. Refer to the LICENSE file for complete details.
 *****************************************************************************/

#define TRIG_PIN 9   // Trigger pin
#define ECHO_PIN 10  // Echo pin

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  delay(2000);
  Serial.println("AYNOP: Ultrasonic Distance Meter");
}

// Function to take one distance reading
float readDistance() {
  // Send a short HIGH pulse to trigger measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time it takes for the echo
  long duration = pulseIn(ECHO_PIN, HIGH, 70000); // 70ms max wait
  float distance = duration * 0.034 / 2;          // Convert to cm

  // Check if distance is valid
  if (distance >= 2 && distance <= 400) {
    return distance;
  } else {
    return -1; // Invalid result
  }
}

void loop() {
  float distance = -1;

  // Try up to 3 times
  for (int i = 0; i < 3; i++) {
    distance = readDistance();
    if (distance != -1) break; // Stop if we got a valid value
  }

  if (distance != -1) {
    Serial.print("Object Distance from Sensor: ");
    Serial.print(distance, 1); // Print with 1 decimal place
    Serial.println(" cm");
  } else {
    Serial.println("No Object");
  }

  delay(500); // Wait half a second before next measurement
}
