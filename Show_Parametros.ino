void Parametros() {
  
  //BLUE 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("HBON:"));
  lcd.setCursor(6,0);
  lcd.print(hbon);
  lcd.setCursor(9,0);
  lcd.print(F("MBON:"));
  lcd.setCursor(14,0);
  lcd.print(mbon);
  delay(500);
  
  //HBOFF
  lcd.setCursor(0,1);
  lcd.print(F("HBOF:"));
  lcd.setCursor(7,1);
  lcd.print(hboff);
  lcd.setCursor(9,1);
  lcd.print(F("MBOF:"));
  lcd.setCursor(14,1);
  lcd.print(mboff);
  delay (6000);
  
/*
    //WHITE
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("HWON:"));
  lcd.setCursor(6,0);
  lcd.print(hwon);
  lcd.setCursor(9,0);
  lcd.print(F("MWON:"));
  lcd.setCursor(14,0);
  lcd.print(mwon);
  
  //HBOFF
  lcd.setCursor(0,1);
  lcd.print(F("HWOF:"));
  lcd.setCursor(7,1);
  lcd.print(hwoff);
  lcd.setCursor(9,1);
  lcd.print(F("MWOF:"));
  lcd.setCursor(14,1);
  lcd.print(mwoff);
  delay (6000);
*/
  
  }













