#include "Sensors.h"


Sensors::Sensors(int dhtPin, int soilMoisturePin, int dhtType) 
      : dht(dhtPin, dhtType), soilMoisturePin(soilMoisturePin){}

void Sensors::init(){

    // dht = DHT(dhtPin, dhtType);
    dht.begin();
    pinMode(soilMoisturePin, INPUT);

}

void Sensors::readSensors() {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    soilMoisture = analogRead(soilMoisturePin);

    int moisturePercentage = map(soilMoisture, 4095, 0, 0, 100);

    if (isnan(temperature) || isnan(humidity)) {
        // Serial.println("Failed to read from DHT sensor!");
        // return;
    }
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Soil Moisture Level: ");
    Serial.print(moisturePercentage);
    Serial.println(" %");
}

Sensors::~Sensors()
{
}
