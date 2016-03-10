void Control(){  
 
  DateTime now = RTC.now();
  h = now.hour();
  m = now.minute();
  
  
   //**** ON ****
  //Blue
   //Ligar o arduino no inicio do hor
   if(h == hbon && m == mbon && currentMillis == 0 && stateBlue == 0 && stateWhite == 0){
      stateBlue = 1;
      stateWhite = 0;
      currentMillis = millis();
      digitalWrite(RL2_BLUE,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Ligou no inicio"));
      delay(2000);
    }
    
    /*
    //Ligar o arduino a meio do hor
  if(((h >= hbon && h <= hboff ) || (h >= 0 && h < hboff )) && stateM == 1){
    stateBlue = 1;
      currentMillis = millis();
      digitalWrite(RL2_BLUE,LOW);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Ligou no meio"));
      delay(2000);
    }
  */
   
  //White
    if(stateBlue == 1 && stateWhite == 0 && timeOnBlue <= (millis() - currentMillis) ){
      stateBlue = 1;
      stateWhite = 1;
      digitalWrite(RL1_WHITE,LOW);
      currentMillis = millis();
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Ligou na continuacao"));
      delay(2000);
      
      
    }
  
  
  //****** OFF *******
  //White
  if(stateBlue == 1 && stateWhite == 1 && timeOnWhite <= (millis() - currentMillis)){
      stateBlue = 0;
      stateWhite = 0;
      stateOff = 1;
      digitalWrite(RL1_WHITE,HIGH);
      currentMillis = millis();
    }
    
  //Blue
  if(stateWhite == 0 && stateBlue == 0 && currentMillis !=0 && timeOnBlue <= (millis() - currentMillis)){
      stateBlue = 0;
      stateWhite = 0;
      stateOff = 0;
      currentMillis = 0;
      digitalWrite(RL2_BLUE,HIGH);
      digitalWrite(RL1_WHITE,HIGH);
    }
     
  
   
//************************************************************************************    
//Controlo modo manual 10 minutos

 //**** ON ****
  //Blue
  if( stateL == 1 ) {
    stateBlue = 1;
    stateWhite = 0;
    currentMillis = millis();
    digitalWrite(RL2_BLUE,LOW);
    
    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Ligou no Manual"));
      delay(2000);
    
  }
   
  //White
    if(stateL == 1 && timeOn2 <= (millis() - currentMillis) ){
      stateBlue = 1;
      stateWhite = 1;
      digitalWrite(RL1_WHITE,LOW);
      currentMillis = millis();
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Ligou no Manual"));
      delay(2000);
      
    }
  
  
  //****** OFF *******
  //White
  if(stateL == 1 && timeOn10 <= (millis() - currentMillis)){
    stateBlue = 1;
    stateWhite = 0;
    digitalWrite(RL1_WHITE,HIGH);
    currentMillis = millis();
    }
 
 //Blue   
  if(stateL == 1 && timeOn2 <= (millis() - currentMillis)){
      stateBlue = 0;
      stateWhite = 0;
      digitalWrite(RL2_BLUE,HIGH);
      digitalWrite(RL1_WHITE,HIGH);
      currentMillis = 0;
    }
   
         
  
  }








