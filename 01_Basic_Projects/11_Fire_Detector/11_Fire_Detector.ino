/****************************************************************************
 * File:        11_Fire_Detector.ino
 * Project:     Fire Detection 
 * Author:      AYNOP Enterprises
 * Created:     26-08-2025
 * Version:     1.2
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Fire detection using a 3-pin Flame Sensor module with:
 *     - Simple filter (100 ms confirmation).
 *     - Print only on state change.
 *     - Lockout period: once flame is detected, input is ignored for 5 sec.
 *   - The sensor gives a LOW signal when flame is detected.
 *   - Onboard LED (pin 13) follows detection state.
 *
 * Revision History:
 *   v1.0 - First version 
 *
 * License:
 *   This content (source code and documentation) is licensed under 
 *   Creative Commons BY-NC-SA 4.0. © 2025 AYNOP. You may use, modify, 
 *   and share for personal and educational purposes only. Commercial 
 *   use or redistribution without prior written permission is strictly 
 *   prohibited. Refer to the LICENSE file for complete details.
 *****************************************************************************/

#define FLAME_PIN 2   // DO pin from Flame Sensor
#define LED_PIN 13    // Onboard LED

int lastState = HIGH;   // assume no flame at start
unsigned long confirmTime = 100; // 100 ms filter time
unsigned long lockoutPeriod = 5000; // 5 sec lockout
unsigned long lastFlameTime = 0;

void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  delay(2000);
  Serial.println("AYNOP: Fire Detector Started ");
}

void loop() {
  unsigned long now = millis();

  // During lockout, skip checking
  if (now - lastFlameTime < lockoutPeriod) {
    return;
  }

  int currentState = digitalRead(FLAME_PIN);

  // If state is different from last known, wait a little to confirm
  if (currentState != lastState) {
    delay(confirmTime);
    int checkState = digitalRead(FLAME_PIN);

    if (checkState == currentState) {  
      lastState = currentState;  // accept new state

      if (currentState == LOW) {
        Serial.println("🔥 Flame Detected!");
        digitalWrite(LED_PIN, HIGH);
        lastFlameTime = now; // start lockout
      } else {
        Serial.println("No Flame");
        digitalWrite(LED_PIN, LOW);
      }
    }
  }

  delay(20); // small delay to avoid busy loop
}
