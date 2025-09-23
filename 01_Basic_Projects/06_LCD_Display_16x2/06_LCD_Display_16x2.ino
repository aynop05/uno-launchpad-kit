/****************************************************************************
 * File:        06_LCD_I2C_Display_16x2.ino
 * Project:     LCD Display - 16X2 (I2C, Typewriter Effect)
 * Author:      AYNOP Enterprises
 * Created:     11-09-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   This project demonstrates how to use a 16x2 LCD with I2C interface.
 *   The LCD prints text character by character (like typing). 
 *   After finishing both lines, it waits and then repeats.
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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create LCD object (address 0x27, 16 chars, 2 lines)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Messages to display
String line1 = "Hello Genius";
String line2 = "AYNOP Enterprises";

void setup() {
  lcd.init();       // Initialize I2C LCD
  lcd.backlight();  // Turn on LCD backlight
}

void loop() {
  lcd.clear();

  // Print Line 1 character by character
  lcd.setCursor(0, 0);
  for (int i = 0; i < line1.length(); i++) {
    lcd.print(line1[i]);
    delay(200); // Delay between each character
  }

  // Print Line 2 character by character
  lcd.setCursor(0, 1);
  for (int i = 0; i < line2.length(); i++) {
    lcd.print(line2[i]);
    delay(200); // Delay between each character
  }

  delay(2000); // Pause after message is complete
}