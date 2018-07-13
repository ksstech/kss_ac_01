/****************************************************************************** 
EWMv1.3c Board 
Test Program for the I2C PCA9555

 created 2017
 by esp8266-projects.com
******************************************************************************/ 

#include <Wire.h> 

//Define the devices you'll use
#define LED 23 //using a EWMV1.3c Board,, LED is on pin 23
#define PCA9555 0x20 // 0x20 is default address 

// At reset, PCA9555 ports are inputs with a high value resistor pull-ups to VDD (100k)
// If relays turning on during power up are a problem. Add a pull down resistor to each relay transistor base.

#define IN_P0 0x00 // Read Input port0
#define IN_P1 0x01 // Read Input port1
#define OUT_P0 0x02 // Write Output port0
#define OUT_P1 0x03 // Write Output port1
#define INV_P0 0x04 // Input Port Polarity Inversion port0 if B11111111 is written input polarity is inverted
#define INV_P1 0x05 // Input Port Polarity Inversion port1 if B11111111 is written input polarity is inverted
#define CONFIG_P0 0x06 // Configuration port0 configures the direction of the I/O pins 0 is output 1 is input
#define CONFIG_P1 0x07 // Configuration port1 configures the direction of the I/O pins 0 is output 1 is input

#define PAUSE 500

void LED_ON()
{
  digitalWrite(LED,LOW);
  delay (PAUSE/2);
  digitalWrite(LED,HIGH);  
}

 void write_io(int command, int value)
{
  Wire.beginTransmission(PCA9555);
  Wire.write(command),Wire.write(value);
  Wire.endTransmission();
}

void setup()
{
  pinMode(LED,OUTPUT);
  delay(10);
  digitalWrite(LED,HIGH);

  Wire.begin(); // join i2c bus (address optional for master) tried to get working
  write_io (CONFIG_P0, B00000000); //defines all pins on Port0 are outputs
  write_io (CONFIG_P1, B00000000); //defines all pins on Port1 are outputs  
  write_io (OUT_P0, B00000000); //clears all relays
  write_io (OUT_P1, B00000000); //clears all relays
  delay (PAUSE);
}


void loop()
{
  //1-WIRE_04
  digitalWrite(LED,HIGH);
  write_io (OUT_P0, B00000001);
  write_io (OUT_P1, B10000000);
  delay (PAUSE);

 LED_ON();
  
  //1-WIRE_03t
  write_io (OUT_P0, B00000010);
  write_io (OUT_P1, B01000000);  
  delay (PAUSE);
  
 LED_ON();
  
  //1-WIRE_02
  write_io (OUT_P0, B00000100);
  write_io (OUT_P1, B00100000);
  delay (PAUSE);
  
 LED_ON();

  //1-WIRE_01
  write_io (OUT_P0, B00001000);
  write_io (OUT_P1, B00010000);  
  delay (PAUSE);
 
 LED_ON();
  
    //1-WIRE_05
  write_io (OUT_P0, B10000000);
  write_io (OUT_P1, B00001000);
  delay (PAUSE);

 LED_ON();

   //1-WIRE_06
  write_io (OUT_P0, B01000000);
  write_io (OUT_P1, B00000100);
  delay (PAUSE);

 LED_ON();

   //1-WIRE_07
  write_io (OUT_P0, B00100000);
  write_io (OUT_P1, B00000010);
  delay (PAUSE);

 LED_ON();

   //1-WIRE_08
  write_io (OUT_P0, B00010000);
  write_io (OUT_P1, B00000001);  
  delay (PAUSE);

 LED_ON();
 
  write_io (OUT_P0, B00000000);
  write_io (OUT_P1, B00000000);
  delay (PAUSE);  
}
 

