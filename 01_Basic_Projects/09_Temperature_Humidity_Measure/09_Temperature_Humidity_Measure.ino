/****************************************************************************
 * File:        09_Temperature_Humidity_Measure.ino
 * Project:     Temperature & Humidity Measurement (DHT11)
 * Author:      AYNOP Enterprises
 * Created:     19-08-2025
 * Version:     1.0
 * Target:      Arduino UNO R4 Minima 
 * IDE:         Arduino IDE 2.3.6 or later
 *
 * Description:
 *   Simple project to read temperature and humidity values from a
 *   DHT11 module and print them on the Serial Monitor.
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

#include "DHT.h"

#define DHTPIN 2       // DHT11 data pin connected to Arduino digital pin 2
#define DHTTYPE DHT11  // Sensor type is DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // Start Serial Monitor
  dht.begin();          // Start DHT11 sensor
  delay(2000);          
  Serial.println("AYNOP: Temperature & Humidity Measurement");
}

void loop() {
  float h = dht.readHumidity();      // Read humidity (%)
  float t = dht.readTemperature();   // Read temperature (Celsius)

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  Serial.println("----------------------");

  delay(2000);   // Wait 2 seconds before next reading
}
