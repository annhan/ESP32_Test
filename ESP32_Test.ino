#include "EEPROM.h"
#include <N_ESP32WEBSERVER.h>
#include <WiFi.h>
#include "Variable_html.h"
#include "Variable_wifi.h"
#include <ESP32HTTPUpdateServer.h>
/*###########################
 UART 0 rxPin = 3;txPin = 1;
 UART 1 rxPin = 9;txPin = 10;
 UART 2 rxPin = 16;txPin = 17;
*/
HardwareSerial Serial2(2);

N_ESP32WEBSERVER server(4999);
ESP32HTTPUpdateServer httpUpdater;

//############################
const char* update_path = "/firmware";
const char* update_username = "mhome";
const char* update_password = "fibaro";
//##########################################
static int taskCore = 1;
 
void coreTask( void * pvParameters ){
 
    String taskMessage = "Task running on core ";
    taskMessage = taskMessage + xPortGetCoreID();
 
    while(true){
        server.handleClient();
    }
 
}
void setup()
{
    Serial.begin(115200);
    Serial2.begin(115200);
    EEPROM.begin(1024);
    WiFi.disconnect(true);
    loadWiFiConf();
    wifi_staticip(WiFiConf.sta_ip,WiFiConf.sta_gateway,WiFiConf.sta_subnet);   
    wifi_connect(WIFI_AP_STA,WiFiConf.sta_ssid,WiFiConf.sta_pwd,WiFiConf.ap_ssid);
    httpUpdater.setup(&server, update_path, update_username, update_password);
    setupWeb();
    setupWiFiConf();
    server.begin();
    xTaskCreatePinnedToCore(
                        coreTask,   /* Function to implement the task */
                        "coreTask", /* Name of the task */
                        10000,      /* Stack size in words */
                        NULL,       /* Task input parameter */
                        0,          /* Priority of the task */
                        NULL,       /* Task handle. */
                        taskCore);  /* Core where the task should run */
}

void loop()
{       
        Serial2.println("AA");
        delay(1000); 
}

 


