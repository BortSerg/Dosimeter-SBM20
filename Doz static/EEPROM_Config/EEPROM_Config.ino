#include <EEPROM.h>

struct ESP_Config {                         //структура для хранения настроек в EEPROM памяти. Переменные структуры записаны большими буквами, для их отличия от других глобальных переменных
  char    MUSOR[16] = {};                   //В начале сектора EEPROM содержатся какие-то данные ESP, запись туда важных данных нежелательна
  // Наименование в режиме клиента
  char    WIFI_SSID[32] = {};               //имя сети
  char    WIFI_PASSWORD[32] = {};
  // Параметры подключения в режиме точки доступа
  char    AP_SSID[32] = {};                 //имя точки доступа
  char    AP_PASSWORD[32] = {};
  // Время экспозиции и отправка данных
  uint16_t EXPOSITION = 5;
  bool    SEND_NM = false;                  //разрешение на отправку данных Narodmon.ru
} Config;

void setup() {

    String ssid = "**your Name SSID**";               //Вписать SSID вашей сети
    String pass = "**your ssid password**";           // и пароль от сети 
    String ap_ssid = "Dosimetr";
    String ap_pass = "";
    strcpy(Config.WIFI_SSID, ssid.c_str());
    strcpy(Config.WIFI_PASSWORD, pass.c_str());
    strcpy(Config.AP_SSID, ap_ssid.c_str());
    strcpy(Config.AP_PASSWORD, ap_pass.c_str());
    Config.EXPOSITION = 60;
    Config.SEND_NM = false;

   size_t sz1 = sizeof(Config);
  for (unsigned int i = 0; i < sz1; i++)
    EEPROM.write(i, *((uint8_t*)&Config + i));

  EEPROM.commit();

  Serial.println ("EEPROM memory flashed successfully");
  
  sz1 = sizeof(Config);
   for( int i=0; i<sz1; i++ ){
       uint8_t c = EEPROM.read(i);
       *((uint8_t*)&Config + i) = c; 
    }
  Serial.println ("\n\n");
  Serial.println ("Subtraction of data. The following parameters are written into memory:");
  Serial.println (String(Config.WIFI_SSID));
  Serial.println (String(Config.WIFI_PASSWORD));
  Serial.println (String(Config.AP_SSID));
  Serial.println (String(Config.AP_PASSWORD));
  Serial.println (String(Config.EXPOSITION));
  Serial.println (String(Config.SEND_NM));

  Serial.println ("\n\n");
  Serial.println ("EEPROM memory prepared successfully. You can flash the main firmware");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
