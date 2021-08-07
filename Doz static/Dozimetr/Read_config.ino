void Read_Config(void){                                   //чтение конфига из EEPROM памяти
   size_t sz1 = sizeof(Config);
   for( int i=0; i<sz1; i++ ){
       uint8_t c = EEPROM.read(i);
       *((uint8_t*)&Config + i) = c; 
    }
 
set_time_expo =  Config.EXPOSITION * 60000;
}
