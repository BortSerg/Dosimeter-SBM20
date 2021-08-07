void SendToNM(){
  if (WiFi.status() == WL_CONNECTED)
  if (Config.SEND_NM == true)
  {
    
     String buf;                                 // Буфер для отправки на NarodMon
      buf = "#" + WiFi.macAddress() + "\n";
      buf.replace(":", "");                      // Формируем заголовок удаляет ":" в данных, например в МАС адресе

      buf = buf + "#SBM20";                      // ID датчика

      buf = buf + "#" + String(temp) + "\n";   // Добавляем в пакет данных значение 

      buf = buf + "##\n";                      // закрываем пакет

      
      client.connect("narodmon.ru", 8283);                            //Подключаемся
      client.print(buf);                                              // И отправляем данные
      Serial.println("============");
      Serial.println("Data sendet to NarodMon");
      Serial.println(buf);                                            //Что отправили на narodmon.ru вывети в консоль
      Serial.println("============\n");
     
   }
  
}
