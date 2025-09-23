/****************************************************************************
 * File:        10_Light_Meter.ino
 * Project:     Light_Meter using (LDR)
 * Author:      AYNOP Enterprises
 * Created:     25-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Reads a photoresistor (LDR) on analog pin A0 and prints a simple light
 *   level to the Serial Monitor. Also turns the onboard LED on when it's dark.
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

// Pins
const int ldrPin = A0;   // LDR voltage divider output → A0
const int ledPin = 13;   // Onboard LED

// Simple threshold (tune after testing): lower value = darker
int darkThreshold = 350; // Try 350; adjust to your room lighting

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("AYNOP: LDR Light Meter");
  Serial.println("-------------------------------");
}

void loop() {
  // Read the LDR once (0..1023 from 10-bit ADC)
  int sensorValue = analogRead(ldrPin);

  // Convert to a rough percentage (0 = dark, 100 = bright)
  int lightPercent = map(sensorValue, 0, 1023, 0, 100);
  if (lightPercent < 0)   lightPercent = 0;
  if (lightPercent > 100) lightPercent = 100;

  // Simple LED indicator: ON when it's dark
  if (sensorValue < darkThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Print result
  Serial.print("Raw: ");
  Serial.print(sensorValue);
  Serial.print("   Light: ");
  Serial.print(lightPercent);
  Serial.println("%");

  delay(300); // Update about 3 times per second
}
