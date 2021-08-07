void display_ip()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("IP Address");
    display.println("");
    display.println(WiFi.softAPIP());
    display.display();
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("IP Address");
    display.println("");
    display.println(WiFi.localIP());
    display.display();
  }
  premillis_disp = millis();
}

void display_out()
{

  if (display_number == false)                            //1 страница
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println(" ");
    display.setTextSize(2);
    if (temp > 1000)                                         //мощность дозы в [мили]рентгенах
      display.println(String(temp  / 1000) + " mR/h");
    else
      display.println(String(temp) + " mkR/h");              //мощность дозы в [микро]рентгенах
     
    display.display();
  }


  if (display_number == true)                               //2 страница
  {
    
    time_on = millis();
    hh = time_on / 3600000;
    time_on = time_on % 3600000;
    mm = time_on / 60000;
    time_on = time_on % 60000;
    ss = time_on / 1000;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Time expo " + String(Config.EXPOSITION) + " min" );
    /*
    display.print("Time ON         ");                                                  //время наработки после сключения
    if (hh < 10)
      display.print("0" + String(hh));
    else
      display.print(String(hh));
    if (mm < 10)
      display.print(":0" + String(mm));
    else
      display.print(":" + String(mm));
    
      if (ss < 10)
      display.println(":0" + String(ss));
      else
      display.println(":" + String(ss));
    
    if (dose > 720)                                                                   //если доза за время наработки больше суточной нормы
    { display.println("Dose " + String(dose) + " mkR !!!");
      display.println();
      display.println("Daily dose 720 mkR");
    }                                         //вывод дозы и предупреждения
    else
      display.println("Dose " + String(dose) + " mkR");                               //вывод только дозы
    display.println();
    */
    display.display();
   
  }
}
