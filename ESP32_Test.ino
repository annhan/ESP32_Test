#include "EEPROM.h"
#include <N_ESP32WEBSERVER.h>
#include <WiFi.h>
#include "Variable_html.h"
#include "Variable_wifi.h"
#include <ESP32HTTPUpdateServer.h>
N_ESP32WEBSERVER server(4999);
ESP32HTTPUpdateServer httpUpdater;
const char* update_path = "/firmware";
const char* update_username = "mhome";
const char* update_password = "fibaro";
void setup()
{
    Serial.begin(115200);
    Serial.println("Begin");
    EEPROM.begin(1024);
    WiFi.disconnect(true);
    loadWiFiConf();
    wifi_staticip(WiFiConf.sta_ip,WiFiConf.sta_gateway,WiFiConf.sta_subnet);   
    wifi_connect(WIFI_AP_STA,WiFiConf.sta_ssid,WiFiConf.sta_pwd,WiFiConf.ap_ssid);
    httpUpdater.setup(&server, update_path, update_username, update_password);
    setupWeb();
    setupWiFiConf();
    server.begin();
}

void loop()
{   server.handleClient();
}

