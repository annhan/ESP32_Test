bool loadWiFiConf() {
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
}

void parseBytes1(const char* str, char sep, int address, int maxBytes, int base) {
  for (int i = 0; i < maxBytes; i++) {
    if (address == 1) ip10[i] = strtoul(str, NULL, base);  // Convert byte
    else if (address == 2) gateway10[i] = strtoul(str, NULL, base);  // Convert byte
    else if (address == 3) subnet10[i] = strtoul(str, NULL, base);  // Convert byte
    Serial.println(ip10[i]);
    str = strchr(str, sep);               // Find next separator
    if (str == NULL || *str == '\0') {
      break;                            // No more separators, exit
    }
    str++;                                // Point to next character after separator
  }
}
