/*
 *  This sketch shows the WiFi event usage
 *
 */
#include <Preferences.h>

#include <WiFi.h>

const char* ssid     = "mHomeRD_B";
const char* password = "123789456";

IPAddress ip10;
IPAddress gateway10;
IPAddress subnet10;
IPAddress DNS(8, 8, 8, 8);

Preferences preferences;
struct WiFiConfStruct {
  String sta_ssid;
  String sta_pwd;
  String sta_ip;
  String sta_gateway;
  String sta_subnet;
} WiFiConf = {
  "hghg",
  "",
  "192.168.1.240",
  "192.168.1.1",
  "255.255.255.0"
};

void WiFiEvent(WiFiEvent_t event)
{
    Serial.printf("[WiFi-event] event: %d\n", event);

    switch(event) {
    case SYSTEM_EVENT_STA_GOT_IP:
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        Serial.println("WiFi lost connection");
        break;
    }
}


void setup()
{
    Serial.begin(115200);
    WiFi.disconnect(true);
    loadWiFiConf();
    delay(1000);
    WiFi.onEvent(WiFiEvent);
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid, password);
    Serial.println();
    Serial.println("Wait for WiFi... ");
}


void loop()
{
    delay(1000);
}



