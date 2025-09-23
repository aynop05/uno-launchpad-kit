/********************************************************************************************
 * File:        04_Passive_Buzzer_Sound.ino
 * Project:     Passive Buzzer Sound
 * Author:      AYNOP Enterprises
 * Created:     18-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   This project introduces the passive buzzer by playing a few simple tones 
 *   directly using the Arduino tone() function. 
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

// Define buzzer pin
const int buzzerPin = 8;

void setup() {
  // No setup required for tone() function
}

void loop() {
  // Play three simple tones (C, D, E)
  
  tone(buzzerPin, 262, 500);   // C4 note, 262 Hz for 500 ms
  delay(600);                  // wait before next note
  
  tone(buzzerPin, 294, 500);   // D4 note, 294 Hz for 500 ms
  delay(600);
  
  tone(buzzerPin, 330, 500);   // E4 note, 330 Hz for 500 ms
  delay(600);
  
  noTone(buzzerPin);           // Stop playing sound
  delay(1000);                 // Pause before repeating
}