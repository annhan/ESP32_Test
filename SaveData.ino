/*bool loadWiFiConf() {
  preferences.begin("wifi", false);
  Serial.println(F("loading WiFiConf"));
  WiFiConf.sta_ssid=preferences.getString("ssid","none");
  WiFiConf.sta_pwd=preferences.getString("password","none");
  WiFiConf.sta_ip=preferences.getString("ip","none");
  WiFiConf.sta_gateway=preferences.getString("gateway","none");
  WiFiConf.sta_subnet=preferences.getString("subnet","none");
  char new_ip[20];
  WiFiConf.sta_ip.toCharArray(new_ip, sizeof(new_ip));
  char new_gateway[20];
  WiFiConf.sta_gateway.toCharArray(new_gateway, sizeof(new_gateway));
  char new_subnet[20];
  WiFiConf.sta_subnet.toCharArray(new_subnet, sizeof(new_subnet));
  parseBytes1(new_ip, '.', 1, 4, 10);
  parseBytes1(new_gateway, '.', 2, 4, 10);
  parseBytes1(new_subnet, '.', 3, 4, 10);
  preferences.end();
}
void saveWiFiConf(void) {
  preferences.begin("wifi", false);
  preferences.putString("ssid",WiFiConf.sta_ssid);
  preferences.putString("password",WiFiConf.sta_pwd);
  preferences.putString("ip",WiFiConf.sta_ip);
  preferences.putString("gateway",WiFiConf.sta_gateway);
  preferences.putString("subnet",WiFiConf.sta_subnet);
  preferences.end();
}*/
void printWiFiConf(void) {
  //Serial.println(WiFiConf.sta_ssid);
}
bool loadWiFiConf() {
  //Serial.println(F("loading WiFiConf"));
  if (EEPROM.read(WIFI_CONF_START + 0) == wifi_conf_format[0] &&
      EEPROM.read(WIFI_CONF_START + 1) == wifi_conf_format[1] &&
      EEPROM.read(WIFI_CONF_START + 2) == wifi_conf_format[2] &&
      EEPROM.read(WIFI_CONF_START + 3) == wifi_conf_format[3])
  {
    for (unsigned int t = 0; t < sizeof(WiFiConf); t++) {
      *((char*)&WiFiConf + t) = EEPROM.read(WIFI_CONF_START + t); //& là địa chỉ  của biến Struc, *là data tức là gán data trong ô nhớ struc bằng eprom đọc dc (char*) là ép kiểu dữ liệu
    }
    printWiFiConf();
    return true;
  } else {
    return false;
  }
}
void saveWiFiConf(void) {
  for (unsigned int t = 0; t < sizeof(WiFiConf); t++) {
    EEPROM.write(WIFI_CONF_START + t, *((char*)&WiFiConf + t));
  }
  EEPROM.commit();
  printWiFiConf();
}




