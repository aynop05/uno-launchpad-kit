/********************************************************************************************
 * File:        03_Read_Analog_Voltage.ino
 * Project:     Read Analog Voltage (via 10K potentiometer )
 * Author:      AYNOP Enterprises
 * Created:     18-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Reads an analog voltage value from pin A0 and converts it into a real-world 
 *   voltage representation. The value is then printed to the Serial Monitor.
 *   The UNO R4 Minima uses a 10-bit ADC (Analog-to-Digital Converter), which 
 *   means the analogRead() function gives values from 0 to 1023, representing 
 *   voltages from 0V to 5V.
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

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the input on analog pin A0
  // Since UNO R4 has a 10-bit ADC, the range is 0–1023
  int sensorValue = analogRead(A0);

  // Convert the analog reading (0–1023) to a voltage (0–5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Print the voltage value to the Serial Monitor
  Serial.println(voltage);

  // Small delay to make output easier to read
  delay(500);
}
