#include <Arduino.h>
class Network{
private:
    char* ssid;
    char* password;
public:
    Network(char* ssid, char* password);
    void connect();
    String GET(const char *url);
    String POST(const char *url, const String &payload);
    ~Network();
};