/****************************************************************************
 * File:        14_IR_Remote_Read.ino
 * Project:     IR Remote Key Reading (HX1838)
 * Author:      AYNOP Enterprises
 * Created:     25-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   This project demonstrates how to read signals from an IR remote using
 *   the HX1838 IR receiver module and print the decoded values to the 
 *   Serial Monitor. Repeat codes (0x0) are ignored for clarity.
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

#include <IRremote.h>   // IRremote library by shirriff

#define IR_RECEIVE_PIN  2   // IR receiver pin connected to Arduino digital pin 2

void setup() {
  Serial.begin(9600);           // Start Serial Monitor
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  
  delay(2000);
  Serial.println("AYNOP: IR Remote Test");
  Serial.println("Press any key on the remote...");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;

    // Ignore repeat codes (0x0)
    if (value != 0x0) {
      Serial.print("Key pressed: 0x");
      Serial.println(value, HEX);
    }

    IrReceiver.resume(); // Receive next value
  }
}