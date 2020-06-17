# Dosimeter-SBM20
Household dosimeter gamma and hard beta radiation. Performed on ESP8266 and SBM20 detector

The project has three firmware options. 
1. For the stationary device dozimetr.zip (there is a web iterise, sending data to narodmon.ru)
2. Mobile version with the web interface dozimetr_mob+web.zip
3. Mobile without web interface Dozimetr_mob_notweb.zip

For the first two versions it isit is possible to view values through a web browser, change settings, as well as update firmware in OTA mode or through the web interface by going to the address http://{IP Address}/update.

These two archives contain two files for firmware. First you need to flash the EEPROM_Config.bin file, and then the Dozimetr.bin or Dozimetr_mob+web.bin executable file.

For the mobile version without a web interface, you need to flash only one file 1.Dozimetr_mob_notweb.bin

