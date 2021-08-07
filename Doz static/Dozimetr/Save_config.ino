//Сохранение параматров в памяти устройства
void HTTP_handleSave (void) {

  bool changeWIFI  = false;

  if (server.hasArg("wifi_ssid") & server.hasArg("wifi_password") & server.hasArg("ap_ssid") & server.hasArg("ap_password"))
  {
    strcpy(Config.WIFI_SSID, server.arg("wifi_ssid").c_str());
    strcpy(Config.WIFI_PASSWORD, server.arg("wifi_password").c_str());
    strcpy(Config.AP_SSID, server.arg("ap_ssid").c_str());
    strcpy(Config.AP_PASSWORD, server.arg("ap_password").c_str());
    changeWIFI = true;
    save_Config();
    Serial.println("Настройки сети сохранены в EEPROM память.\n");
  }

  if (server.hasArg("expo") & server.hasArg("send_NM"))
  {
    Config.EXPOSITION = server.arg("expo").toInt();
    set_time_expo =  Config.EXPOSITION * 60000;
    if (atoi(server.arg("send_NM").c_str()) == 1) Config.SEND_NM = true; else Config.SEND_NM = false;
    save_Config();
    Serial.println("Настройки времени экспозиции и отправки данных сохранены в EEPROM память.\n");
  }




  String out = "";
  out += "<!DOCTYPE html>";
  out += "<html>";
  out += "<head>";
  out += "<meta http-equiv=\"Content-Type\" name=\"viewport\" content=\"text/html; charset=utf-8; width=device-width, initial-scale=1, user-scalable=no\" >";
  out += "<title>Save settings</title>";
  out += "<style type=\"text/css\">";
  out +=        "html {padding:0; margin:0;";
  out +=        "height: 100%;";
  out +=        "ckground: #2c3e50; /* fallback for old browsers */";
  out +=        "background: -webkit-linear-gradient(to left, #2c3e50, #4ca1af); /* Chrome 10-25, Safari 5.1-6 */";
  out +=        "background: linear-gradient(to left, #2c3e50, #4ca1af); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */}";

  out +=      "h1{font-style:italic; font-weight:bold; text-align:center; color:white;}";
  out +=      "h2{font-style:italic; text-align:center; color:white;}";
  out +=      "body {padding:0; margin:0;}";
  out +=      ".knopki{position: relative; z-index: 1; text-align: center; height: 35px; width: 100px;}";

  out +=     "@media screen and (max-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:650px){div {text-align: center; margin-left: 100px; margin-right: 100px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:800px){div {text-align: center; margin-left: 200px; margin-right: 200px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:1024px){div {text-align: center; margin-left: 300px; margin-right: 300px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:1280px){div {text-align: center; margin-left: 400px; margin-right: 400px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:1440px){div {text-align: center; margin-left: 500px; margin-right: 500px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:1600px){div {text-align: center; margin-left: 600px; margin-right: 600px; margin-top:20px; margin-bottom:20px;}}";
  out +=     "@media screen and (min-width:1920px){div {text-align: center; margin-left: 700px; margin-right: 700px; margin-top:20px; margin-bottom:20px;}}";
  out += "</style>";
  out += "</head>";

  out += "<body><h1>Конфигурация сохранена</h1>";
  out += "<h2>Перейти на страницу:</h2>";
  out +=     "<div align=\"center\">";
  out +=          "<form action=\"/settings_WiFi_AP\"><button class=\"knopki\" type=\"submit\">WI-FI<br>AP</button></form>";
  out +=          "<br><form action=\"/settings_exposition\"><button class=\"knopki\" type=\"submit\">EXPOSITION<br>NARODMON</button></form>";
  out +=          "<br><form action=\"/\"><button class=\"knopki\" type=\"submit\">Главная</button></form>";
  out +=     "</div>";
  out += "</body>";
  out += "</html>";
  out += "<script type=\"text/javascript\">";
  if (changeWIFI == true)
    out += "alert(\"Для применения сетевых параметров необходима перезагрузка. Перезагрузите устройство вручную\");";

  out += "</script>";
  server.send ( 200, "text/html", out );

}




// * Сохраняем значение конфигурации в EEPROM

void save_Config() {
  size_t sz1 = sizeof(Config);
  for (unsigned int i = 0; i < sz1; i++)
    EEPROM.write(i, *((uint8_t*)&Config + i));

  EEPROM.commit();

}
