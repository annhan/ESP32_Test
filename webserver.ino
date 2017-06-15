void setupWiFiConf(void) {
  server.on("/main", []() {
    //IPAddress ip = WiFi.localIP();
    //String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
    String content = "Page 1";
    server.send(200, F("text/html"), content);
  });
   server.on("/set1", []() {
    String new_IPHC = server.arg(F("ip"));
    String new_pwdhc = server.arg(F("pwd"));
    Serial.println(new_IPHC);
    Serial.println(new_pwdhc);
    server.send(200, F("text/html"), new_IPHC);
  });
}
void setupWeb(void) {
  server.on("/", []() {
    String content = "Hello Server" ;
    server.send(200, F("text/html"), content);

  });
}
