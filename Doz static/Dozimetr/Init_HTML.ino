void Init_html(){
  server.on ( "/", HTTP_Main );                                       //Гдавная страница
  server.on ( "/settings_WiFi_AP", HTTP_Settings_WIFI_AP);            //страница с настройками wifi/ap
  server.on ( "/settings_exposition", HTTP_Settings_EXPOSITION);      //настройка времени экспозиции
  server.on ( "/save", HTTP_handleSave );                             //Запись данных в память устройства
  httpUpdater.setup(&server);     
  server.begin();
}
