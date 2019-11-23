
#include <Arduino.h>
#include "settings.h"
#include "sensor_readings.h"


void refresh_readings(Adafruit_BME280 bme) {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  digitalWrite(LED_BUILTIN, HIGH);

  f_temperature = bme.readTemperature();
  f_humidity = bme.readHumidity();
  f_pressure = bme.readPressure() / 100.0F;
  f_altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // Temperature
  f_temperature = (f_temperature * 9/5) + 32;
  Serial.print(f_temperature);
  Serial.println(" °F");

  // Humidity
  Serial.print(f_humidity);
  Serial.println(" %");

  // Pressure
  Serial.print(f_pressure);
  Serial.println(" hPa");

  // Appx altitude
  f_altitude = f_altitude * 3.28;
  Serial.print(f_altitude);
  Serial.println(" feet");   
  
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("------------");   
}