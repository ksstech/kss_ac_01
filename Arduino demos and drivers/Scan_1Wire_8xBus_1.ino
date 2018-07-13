/****************************************************************************** 
EWMv1.3c Board 
Test Program  - DS2482-800 driver example
1-Wire Bus scanner example

 created 2017
 by esp8266-projects.com
******************************************************************************/ 

#define LED 23

//#include "user_interface.h"
//#include "osapi.h"
//#include "ets_sys.h"
#include "pgmspace.h"
#include <Wire.h>
#include <OneWire.h>

OneWire oneWire;
uint8_t cfg=0;
uint8_t i=0;
int key[8]={1,231,79,222,25,0,0,199};
int mt=0;

void printAddress(uint8_t deviceAddress[8])
{
  Serial.print("{ ");
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    Serial.print("0x");
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    if (i<7) Serial.print(", ");
    yield();
  }
  Serial.print(" }");
}


void printKey(uint8_t deviceAddress[8])
{
  //Serial.print("{ ");
  String str="";
  char buf[17];
  for (i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    //str = String(deviceAddress[i],HEX);
    Serial.print(deviceAddress[i], HEX);
    //Serial.print(deviceAddress[i], DEC);
    if (i<7) Serial.print(":");
    //Serial.print(str);
    yield();

    if (deviceAddress[i]==key[i]){
      mt = mt+1;
    }
  }

  if (mt == 8){
    //Serial.println("\n\t\t\tValid KEY!");
    Serial.print(" - Valid KEY!");
    digitalWrite(LED, HIGH);   
    
  }
 //    Serial.println(mt);
  mt = 0;
  //Serial.print("\n\t\t\tString: ");
  //Serial.println((char*)deviceAddress);
  //Serial.println(sizeof(deviceAddress));

/*  Serial.print("\n\t\t\tBuf: ");

  for (i = 0; i < 8; i++)
  {
   // if (deviceAddress[i] < 16) Serial.print("0");
    buf[i] = deviceAddress[i];
    //Serial.print(buf[i],HEX);
    Serial.print(buf);
    yield();
  }
*/
  delay(1000);
    
}


void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  //ESP.wdtDisable();
  //ESP.wdtEnable(WDTO_8S);
}

void loop()
{
//  ESP.wdtFeed();
  Serial.print("\nChecking for 1-Wire Master : ");
  if (oneWire.checkPresence())
  {
    Serial.println("DS2482-800 present!");
    
    oneWire.deviceReset();
    oneWire.setStrongPullup();
    //OneWire::readConfig();
    //Serial.println(cfg);

    for (int iCH = 0; iCH<8; iCH++ )
    {
        Serial.print("\tActive 1-Wire BUS : ");
        Serial.println(iCH);
        oneWire.selectChannel(iCH);
        //cfg = OneWire::readConfig();
        //Serial.println(cfg);
    
        Serial.print("\tChecking for 1-Wire devices ...");
        if (oneWire.wireReset())
        {
           Serial.println("\tDevices present on 1-Wire bus");
      
           uint8_t currAddress[8];
           uint8_t prevAddress[8];
      
           Serial.println("\t\tSearching 1-Wire bus ...");
      
           while (oneWire.wireSearch(currAddress))
          {
             Serial.print("\t\t\tFound device: ");
             //printAddress(currAddress);
             digitalWrite(LED, HIGH);   
             printKey(currAddress);
             //delayMicroseconds(1000000);
             Serial.println();
             //digitalWrite(LED_BUILTIN, LOW);   
             yield();
          }
         oneWire.wireResetSearch();
       }
       else
         Serial.println("\tNo devices on 1-Wire bus");
    }
   }
  else
    Serial.println("No DS2482-800 present");

   yield(); 
   //delayMicroseconds(1000000);  
  digitalWrite(LED, HIGH);  
  delay(2000);
  digitalWrite(LED, LOW);   
  delay(2000);
}
