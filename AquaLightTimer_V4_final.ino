/************ PeltierDuino ************/
//--- BIBLIOTECAS 
#include <LiquidCrystal.h> 
#include <OneWire.h>
#include <Wire.h>
#include <RTClib.h>  
//#include <Event.h>
//#include <Timer.h>
#include <EEPROM.h>
#include "Variaveis.h"


//--- Inicializacao dos Sensores                                      
RTC_DS1307 RTC;

/* DS18S20 Temperature chip i/o */
OneWire  ds(2);  
#define MAX_DS1820_SENSORS 2
byte addr[MAX_DS1820_SENSORS][8];

#define lightsOn  A1
#define lightsOff A2

// digital pins
#define RL1_WHITE 3    //Power to White lights
#define RL2_BLUE  4    //Power to blue ligths

//--- LCD Key Pad Panel 
LiquidCrystal lcd(12, 13, 11, 10, 9, 8); //nano
//LiquidCrystal lcd(13,12, 11, 10, 9, 8); //uno - Proteus

//--- KEYPAD
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

/**************************** VOID SETUP ******************************/
//--- VOID SETUP 
void setup() {
  
  Serial.begin(9600); 
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);

  // Inicializacao do RTC
  Wire.begin();
  RTC.begin(); 
  
  lcd.clear();
  lcd.print(F("LightDuino V4"));
  
  for(int i=0; i<17; i++){
    lcd.setCursor(i,1);
    lcd.print("-");
    delay(50);
    }
    delay (500);
    
  
  // digital pins
  pinMode(RL1_WHITE,OUTPUT); 
  pinMode(RL2_BLUE,OUTPUT); 
  pinMode(lightsOn,INPUT);
  pinMode(lightsOff,INPUT);
  
  digitalWrite(RL1_WHITE,HIGH); 
  digitalWrite(RL2_BLUE,HIGH);
  
  if (!ds.search(addr[0]))
  {
    lcd.setCursor(0,0);
    lcd.print("No more addresses.");
    ds.reset_search();
    delay(1000);
    return;
  }
  if ( !ds.search(addr[1]))
  {
    lcd.setCursor(0,0);
    lcd.print("No more addresses.");
    ds.reset_search();
    delay(1000);
    return;
  }
  

  
//--- Config values
 Config();            
             
//discoverOneWireDevices();

}


/************************ VOID LOOP ***********************/
void loop() {
  
  delay(25);
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);                   // start the library
  lcd.clear();
  delay(25);
  
    Config();   
    
    Keypad();
    Control();
    Data_Print();
    Keypad();
    Control();
    D18B20();
    Keypad();
    Control();
    Keypad();
    Control();
}

//--- FIM VOID LOOP 
//--- FIM  DO PROGRAMA 







