#include <Arduino.h>
#include "Sensors.h"
#define DHTPIN 5           
#define DHTTYPE DHT22 
#define SOIL_MOISTURE_PIN 4 

Sensors sensors(DHTPIN, SOIL_MOISTURE_PIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  sensors.init();

}

void loop() {

  sensors.readSensors();
  delay(5000);

}
