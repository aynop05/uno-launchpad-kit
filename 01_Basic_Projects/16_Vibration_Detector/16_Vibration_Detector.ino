/****************************************************************************
 * File:        16_Vibration_Detector.ino
 * Project:     Vibration Detection (SW-520D)
 * Author:      AYNOP Enterprises
 * Created:     26-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Beginner-friendly project to detect vibrations using the SW-520D sensor.
 *   When vibration is detected for at least 100 microseconds:
 *     - A message is printed on Serial Monitor.
 *     - The onboard LED blinks for 1 seconds.
 *     - Further detections are blocked for 2 seconds (debounce / lockout).
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

#define VIB_PIN 2        // Vibration sensor connected to digital pin 2
#define LED_PIN 13       // Onboard LED

unsigned long lastTriggerTime = 0;   // To manage 3s lockout

void setup() {
  pinMode(VIB_PIN, INPUT_PULLUP);   // Using internal pull-up
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  delay(2000);  
  Serial.println("AYNOP: Vibration Detector Started");
}

void loop() {
  // Check lockout
  if (millis() - lastTriggerTime < 2000) {
    return; // Skip if within lockout period
  }

  // Read vibration sensor
  if (digitalRead(VIB_PIN) == HIGH) {   // HIGH means vibration (per your observation)
    delayMicroseconds(10);             // Confirm vibration lasted at least 10 µs
    if (digitalRead(VIB_PIN) == HIGH) { // Still vibrating
      Serial.println("Vibration Detected!");
      digitalWrite(LED_PIN, HIGH);
      delay(1000);                      // Keep LED on for 2 seconds
      digitalWrite(LED_PIN, LOW);

      lastTriggerTime = millis();       // Start 2s lockout
    }
  }
}
