#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


void refresh_readings();  // Declare in the header so that the compiler knows about it before it is called in loop()

#ifndef LED_BUILTIN
#define LED_BUILTIN 2   // This is valid for my devkit
#endif

#define SEALEVELPRESSURE_HPA (1028)
Adafruit_BME280 bme; // I2C


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);
  bool status;

  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  refresh_readings();
  delay(2000);
}

void refresh_readings() {
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