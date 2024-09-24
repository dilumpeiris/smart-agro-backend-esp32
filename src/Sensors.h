#include <DHT.h>

class Sensors {
private:
    DHT dht;
    int dhtPin;
    int soilMoisturePin;
    int dhtType;
public:
    float temperature;
    float humidity;
    int soilMoisture;

    Sensors(int dhtPin, int soilMoisturePin, int dhtType);
    void init();
    void readSensors();
    ~Sensors();
};