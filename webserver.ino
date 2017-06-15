void setupWiFiConf(void) {

  server.on("/main", []() {
    //IPAddress ip = WiFi.localIP();
    //String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
    String content = FPSTR(header); content += FPSTR(begin_title);
    String   content1 = FPSTR(p_html);
    content += F("Connected Wifi: ");
    content1 = FPSTR(p_html);
    content1 += WiFiConf.sta_ssid;
    content1 += F("</br>IP Address: ");
    
    content1 += F(" ( ");
    
    content1 += F(".local )");
    content1 += FPSTR(_p_html);
    content1 += FPSTR(p_html);
    content1 += FPSTR(_p_html);
    content1 += FPSTR(get_html);
    content1 += F("'set_wifi_conf'>");
    content1 += F("<div class=\"row\">");
    content1 += FPSTR(label1_html);
    content1 += F("'ssid' class=\"req\">SSID : </label>");
    content1 += F("<input name='ssid'class=\"txt\" id='ssid' maxlength=32 value=") ;
    content1 += String(WiFiConf.sta_ssid) ;
    // content1 +=  FPSTR(br_html);
    content1 += F("></div>");


    content1 += F("<div class=\"row\">");
    content1 += FPSTR(label1_html);
    content1 += F("'pwd' class=\"req\">Password :  </label>");
    content1 += F("<input type='password' class=\"txt\" name='pwd' id='pwd' value=");
    content1 += String(WiFiConf.sta_pwd);


    content1 += F("></div>");

    content1 += F("<div class=\"row\">");
    //content1 += FPSTR(br_html);
    content1 += FPSTR(label1_html);
    content1 += F("'ip' class=\"req\">Ip : </label>");
    content1 += F("<input name='ip' class=\"txt\" id='ip' value=");
    content1 += String(WiFiConf.sta_ip) ;
    //  content1 +=  FPSTR(br_html);
    content1 += F("></div>");
    content1 += F("<div class=\"row\">");
    content1 += FPSTR(label1_html);
    content1 += F("'gateway' class=\"req\" >Gateway :  </label>");
    content1 += F("<input  name='gateway' class=\"txt\" id='gateway' value=") ;
    content1 += String(WiFiConf.sta_gateway) ;
    //content1 += FPSTR(br_html);
    content1 += F("></div>");
    content1 += F("<div class=\"row\">");
    content1 += FPSTR(label1_html);
    content1 += F("'subnet' class=\"req\">Subnet :</label>");
    content1 += F("<input  name='subnet' class=\"txt\" id='subnet' value=");
    content1 +=  String(WiFiConf.sta_subnet);
    // content1 += FPSTR(br_html);
    content1 += F("></div>");

    content += FPSTR(wifisetting_html);
    content += FPSTR(title_html);
    content += F("<h1>Wifi Setup</h1>");

    content += content1;

    content += F("<input type='submit' id=\"submitbtn\" value='OK' onclick='return confirm(\"Change Settings?\");'></form>");

    content += FPSTR(_p_html);
  
    content += FPSTR(end_html);
    server.send(200, F("text/html"), content);
  });
}
void setupWeb(void) {
  server.on("/", []() {
    String content = FPSTR(header);
    content += FPSTR(begin_title);
    content += F("mHome - Main page");
    content += FPSTR(title_html);
    content += F("<h1>mHome - Wifi to IR Controller </h1>");
    content += FPSTR(p_html);
    content += FPSTR(fieldset);



content += F("<li>Học Lệnh : <a href='/learning'>Enable</a>");
    content += FPSTR(_fieldset);
    content += FPSTR(_p_html);
    content += FPSTR(fieldset);

    content += FPSTR(legend_html);
    content += F("'/wifi_conf'>Wifi setting");
    content += FPSTR(_legend_html);
   
      content += F("<li>Connected to : ");
      content += WiFiConf.sta_ssid;
      content += F("<li>IP: ");
     
      content += F(" ( ");
      
      content += F(" )");
    
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/IR'>IR Leaning");
    content += FPSTR(_legend_html);
    content += F("<li>Description: This section is for learning IR code from IR remotes.");
    content += F("<li>Each successful learning code should be copied to use with Fibaro HC2 later");
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/hc2_conf'>HC2 Setting");
    content += FPSTR(_legend_html);
    content += F("<li>Description:This section is for setting communication between HC2 and Wifi IR controller");
    content += F("<li>Status : ");
 
    content += FPSTR(_fieldset);

    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/remote_save'>Setting Remote");
    content += FPSTR(_legend_html);
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/firmware'>Firmware Update");
    content += FPSTR(_legend_html);
    content += F("<li>Description: This section is for update firmware of wifi IR controller");
    content += F("<li>Status : ");

    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/Reboot'>Reboot Wifi IR Controller");
    content += FPSTR(_legend_html);
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/Reset1'>Reset");
    content += FPSTR(_legend_html);
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += FPSTR(legend_html);
    content += F("'/module_id'>Wifi Name");
    content += FPSTR(_legend_html);
    content += FPSTR(_fieldset);
    content += FPSTR(fieldset);
    content += F("<legend>Information</legend>");
    content += FPSTR(information);
    content += FPSTR(_fieldset);
    content += FPSTR(end_html);
    server.send(200, F("text/html"), content);

  });
}
