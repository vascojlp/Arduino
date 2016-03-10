void Prog_Time() {
  
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- PROGRAMACAO -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("- ILUMINACAO -"));
  delay(2000);


  /******************** PROGRAMACAO BLUE LIGHT *****************************/
  //Hora Inicio
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("PROGRAMACAO"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("HORA INICIO:"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("HORA ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(10);
  lcd.print(hbon);
  lcd.setCursor(5, 2);
  lcd.print(F("(Horas)"));
  delay(2000);

  while (btstate == 1) {
    delay(100);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      hbon = hbon + 1;
      if (hbon > 24 || hbon <= 0) hbon = 1;
      EEPROM.write(10, hbon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hbon);
    }

    //btnDOWN
    delay(100);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      hbon = hbon - 1;
      if (hbon > 24 || hbon <= 0) hbon = 1;
      EEPROM.write(10, hbon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hbon);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      hbon = 21;    
      EEPROM.write(10, hbon);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("HORA ACTUAL:"));
      EEPROM.read(10);
      lcd.setCursor(0, 2);
      lcd.print(hbon);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 30) {
      lcd.clear();
      lcd.print(F("NOVA HORA:"));
      EEPROM.read(hbon);
      lcd.setCursor(0, 2);
      lcd.print(hbon);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
      delay(4000);
      btstate = 0 ;
    }
    
    }
  
  
  
  //Minutos Inicio
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("PROGRAMACAO"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("MINUTOS INICIO:"));
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("MIN. ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(20);
  lcd.print(mbon);
  lcd.setCursor(5, 2);
  lcd.print(F("(minutos)"));
  delay(2000);
  
  btstate = 1;

  while (btstate == 1) {
    delay(100);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      mbon = mbon + 1;
      if (mbon > 60 || mbon < 1) mbon = 1;
      EEPROM.write(20, mbon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mbon);
    }

    //btnDOWN
    delay(100);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      mbon = mbon - 1;
      if (mbon > 60 || mbon < 1) mbon = 1;
      EEPROM.write(20, mbon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mbon);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      mbon = 30;    
      EEPROM.write(20, mbon);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("MINUTOS ACTUAL:"));
      EEPROM.read(20);
      lcd.setCursor(0, 2);
      lcd.print(mbon);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
     if (adc_key_in < 30) {
      lcd.clear();
      lcd.print(F("NOVOS MINUTOS:"));
      EEPROM.read(20);
      lcd.setCursor(0, 2);
      lcd.print(mbon);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
      delay(2000);
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      delay(4000);
      btstate = 0 ;
    }
}
  
  
  
 /* 
  //Hora fim
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- BLUE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("HORA FIM:"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("HORA ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(50);
  lcd.print(hboff);
  lcd.setCursor(5, 2);
  lcd.print(F("(Horas)"));
  delay(2000);
btstate = 1;

  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      hboff = hboff + 1;
      if (hboff > 24 || hboff <= 0) hboff = 1;
      EEPROM.write(50, hboff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hboff);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      hboff = hboff - 1;
      if (hboff > 24 || hboff <= 0) hboff = 1;
      EEPROM.write(50, hboff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hboff);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      hboff = 5;    
      EEPROM.write(50, hboff);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("HORA ACTUAL:"));
      EEPROM.read(50);
      lcd.setCursor(0, 2);
      lcd.print(hboff);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 30) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("HORA.ACTUAL:"));
      EEPROM.read(50);
      lcd.setCursor(0, 2);
      lcd.print(hboff);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
      delay(4000);
      btstate = 0 ;
    }
   }
  
  
  //Minutos Fim
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- BLUE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("MINUTOS OFF:"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("MIN. ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(60);
  lcd.print(mboff);
  lcd.setCursor(5, 2);
  lcd.print(F("(minutos)"));
  delay(2000);
  
  btstate = 1;
  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      mboff = mboff + 1;
      if (mboff > 60 || mboff < 1) mboff = 1;
      EEPROM.write(60, mboff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mboff);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      mboff = mboff - 1;
      if (mboff > 60 || mboff < 1) mboff = 1;
      EEPROM.write(60, mboff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mboff);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      mboff = 0;    
      EEPROM.write(60, mboff);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("MINUTOS ACTUAL:"));
      EEPROM.read(60);
      lcd.setCursor(0, 2);
      lcd.print(mboff);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 30) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("MIN.ACTUAL:"));
      EEPROM.read(60);
      lcd.setCursor(0, 2);
      lcd.print(mboff);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
      delay(4000);
      btstate = 0 ;
    }
   }
    
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      //lcd.setCursor(0, 1);
      //lcd.print(F("BLUE LIGHT"));
      
   
  
  
  
  
  //******************** PROGRAMACAO WHITE LIGHT *****************************
  //Hora Inicio
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- WHITE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("-HORA INICIO-"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("HORA ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(30);
  lcd.print(hwon);
  lcd.setCursor(5, 2);
  lcd.print(F("(Horas)"));
  delay(2000);

btstate = 1;
  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      hwon = hwon + 1;
      if (hwon > 24 || hwon <= 0) hwon = 1;
      EEPROM.write(30, hwon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hwon);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      hwon = hwon - 1;
      if (hwon > 24 || hwon <= 0) hwon = 1;
      EEPROM.write(30, hwon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hwon);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      hwon = 22;    
      EEPROM.write(30, hwon);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("HORA ACTUAL:"));
      EEPROM.read(30);
      lcd.setCursor(0, 2);
      lcd.print(hwon);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 50) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("HORA.ACTUAL:"));
      EEPROM.read(hwon);
      lcd.setCursor(0, 2);
      lcd.print(hwon);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
      delay(4000);
      btstate = 0 ;
    }
  }
  
  //Minutos Inicio
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- WHITE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("MINUTOS INICIO"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("MIN. ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(40);
  lcd.print(mwon);
  lcd.setCursor(5, 2);
  lcd.print(F("(minutos)"));
  delay(2000);

btstate = 1;
  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      mwon = mwon + 1;
      if (mwon > 60 || mwon < 1) mwon = 1;
      EEPROM.write(40, mwon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mwon);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      mwon = mwon - 1;
      if (mwon > 60 || mwon < 1) mwon = 1;
      EEPROM.write(40, mwon);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mwon);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      mwon = 45;    
      EEPROM.write(40, mwon);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("MINUTOS ACTUAL:"));
      EEPROM.read(40);
      lcd.setCursor(0, 2);
      lcd.print(mwon);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 50) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("MIN.ACTUAL:"));
      EEPROM.read(mwon);
      lcd.setCursor(0, 2);
      lcd.print(mwon);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
      delay(4000);
      btstate = 0 ;
    }
  }  
  
  
  
  
  //Hora fim
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- WHITE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("HORA FIM:"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("HORA ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(70);
  lcd.print(hwoff);
  lcd.setCursor(5, 2);
  lcd.print(F("(Horas)"));
  delay(2000);

btstate = 1;
  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      hwoff = hwoff + 1;
      if (hwoff > 24 || hwoff <= 0) hwoff = 1;
      EEPROM.write(70, hwoff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hwoff);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      hwoff = hwoff - 1;
      if (hwoff > 24 || hwoff <= 0) hwoff = 1;
      EEPROM.write(70, hwoff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(hwoff);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      hwoff = 4;    
      EEPROM.write(70, hwoff);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("HORA ACTUAL:"));
      EEPROM.read(70);
      lcd.setCursor(0, 2);
      lcd.print(hwoff);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 50) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("HORA.ACTUAL:"));
      EEPROM.read(hwoff);
      lcd.setCursor(0, 2);
      lcd.print(hwoff);
      lcd.setCursor(5, 2);
      lcd.print(F("(horas)"));
      delay(4000);
      btstate = 0 ;
    }
  }
  
  //Minutos Fim
  lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
  lcd.print(F("- WHITE LIGHT -"));
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(F("MINUTOS OFF:"));
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("MIN. ACTUAL:"));
  lcd.setCursor(0, 2);
  EEPROM.read(80);
  lcd.print(mwoff);
  lcd.setCursor(5, 2);
  lcd.print(F("(minutos)"));
  delay(2000);

btstate = 1;
  while (btstate == 1) {
    delay(150);
    //btnUP
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 50 && adc_key_in < 250) {
      mwoff = mwoff + 1;
      if (mwoff > 60 || mwoff < 1) mwoff = 1;
      EEPROM.write(80, mwoff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mwoff);
    }

    //btnDOWN
    delay(150);
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 250 && adc_key_in < 450) {
      mwoff = mwoff - 1;
      if (mwoff > 60 || mwoff < 1) mwoff = 1;
      EEPROM.write(80, mwoff);
      delay(50);
      lcd.setCursor(0, 2);
      lcd.print(mwoff);
    }

    //btnSELECT
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in > 650 && adc_key_in < 850) {
      mwoff = 45;    
      EEPROM.write(80, mwoff);
      delay(50);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("EEPROM CLEARED!"));
      delay (2000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("MINUTOS ACTUAL:"));
      EEPROM.read(80);
      lcd.setCursor(0, 2);
      lcd.print(mwoff);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
    }

    //btnRIGHT - GRAVAR
    adc_key_in = 0;
    adc_key_in = analogRead(0);    // read the value from the sensor
    if (adc_key_in < 50) {
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      delay(2000);
      lcd.clear();
      lcd.print(F("MIN.ACTUAL:"));
      EEPROM.read(mwoff);
      lcd.setCursor(0, 2);
      lcd.print(mwoff);
      lcd.setCursor(5, 2);
      lcd.print(F("(minutos)"));
      delay(4000);
      btstate = 0 ;
    }
   }
      lcd.clear();                                      //Situamos o cursor no caracter 0, linha 0
      lcd.print(F("FIM PROGRAMACAO"));
      lcd.setCursor(0, 1);
      lcd.print(F("WHITE LIGHT"));
      delay(4000);
*/

}











