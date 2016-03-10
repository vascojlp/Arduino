void Data_Print(){
   DateTime now = RTC.now();
    
    lcd.clear(); 
    lcd.print(now.day(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(),DEC);
    lcd.setCursor(0,1);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    delay(2000);
    Keypad();
      
    if(stateWhite == 1 && stateBlue == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Lights ON "));
      lcd.setCursor(0,2);
      lcd.print(F("White and Blue "));
      delay (2000);
      }
      
    Keypad();
    
    if((stateWhite == 0 && stateBlue == 1)||stateOff == 1 ) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Lights ON "));
      lcd.setCursor(0,2);
      lcd.print(F("Blue "));
      delay (2000);
      }
    
    if (stateL == 1 ) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Lights ON for:"));
      timer = (((timeOn10+60000) -(millis() - currentMillis))/1000)/60;
      lcd.setCursor(0, 2);
      lcd.print(timer);
      lcd.setCursor(8,2);
      lcd.print(F("minutos"));
      delay (2000);
      }
      
      Keypad();
      
      if (stateWhite == 1 && stateBlue == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Lights ON for:"));
      timer = (((timeOnWhite+60000) -(millis() - currentMillis))/1000)/60;
      lcd.setCursor(0, 2);
      lcd.print(timer);
      lcd.setCursor(8,2);
      lcd.print(F("minutos"));
      delay (2000);
      }
      
      Keypad();
      
      if ((stateBlue == 1 && stateWhite == 0)||stateOff == 1 ) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Lights ON for:"));
      timer = (((timeOnBlue+60000) -(millis() - currentMillis))/1000)/60;
      lcd.setCursor(0, 2);
      lcd.print(timer);
      lcd.setCursor(8,2);
      lcd.print(F("minutos"));
      delay (2000);
      }
         
    Keypad();
      
 
}


















