void Keypad() 
{
  /*
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;
  */
  /***********************************************************************************************************************************/  
    
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 

k = (analogRead(0) - adc_key_in);    //gives the button a slight range to allow for a little contact resistance
 
 
 //dOUBLE PRESS
 if (5 < abs(k)){
}

//NO Press
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
if (adc_key_in > 1000){  
}
 

//btnLeft 
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
 if (adc_key_in > 450 && adc_key_in < 650){
   Parametros();   
   }
 
 //btnSelect
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
 if (adc_key_in > 650 && adc_key_in < 850){
   btstate = 1;
   Prog_Time();
 }
 
 
 //btnUp
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
 if (adc_key_in > 50 && adc_key_in < 250){
   stateL = 1;
   Control();
   }        
        
//btnDown
adc_key_in =0;
adc_key_in = analogRead(0);    // read the value from the sensor 
 if (adc_key_in > 250 && adc_key_in < 450){
   currentMillis = 0;
   stateL = 0;
   stateBlue = 0;
   stateWhite = 0;
   digitalWrite(RL1_WHITE,HIGH); 
   digitalWrite(RL2_BLUE,HIGH); 
   }
 
}
       


