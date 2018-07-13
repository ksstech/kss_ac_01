/*
 EWM Isolated direct GPIO Input example 

 Turns on and off a light emitting diode(LED) connected to ESP32 digital
 pin 23, when activating a isolated input IN01-04

 created 2017
 by tech@esp8266-projects.com

 */


const int IN04 = 25;     // the number of the INPUT pin:
const int IN03 = 14; 
const int IN02 = 27; 
const int IN01 = 26; 

const int LED =  23;      // the number of the LED pin

// variables will change:
int buttonState4 = 0;         // variable for reading the status
int buttonState1 = 0;         // variable for reading the status
int buttonState2 = 0;         // variable for reading the status
int buttonState3 = 0;         // variable for reading the status


void setup() {
  // initialize the LED pin as an output:
  pinMode(LED, OUTPUT);
  // initialize the pins as an input:
  pinMode(IN04, INPUT);
  pinMode(IN03, INPUT);
  pinMode(IN02, INPUT);
  pinMode(IN01, INPUT);
  Serial.begin(115200);
  Serial.println("\n\nEWM 1.3c init ... \n InputPort test ready.\n");
}

void loop() {
  // read the state of the INPUT pins value:
  buttonState4 = digitalRead(IN04);
  buttonState3 = digitalRead(IN03);
  buttonState2 = digitalRead(IN02);
  buttonState1 = digitalRead(IN01);

  // check if input is active.
  // if it is, the buttonState is LOW:
  if (buttonState4 == HIGH){
    digitalWrite(LED, LOW);
  } else {
    // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.println("Input Event : IN04 - Active!");
    delay(100);
  }
  if (buttonState3 == HIGH){
    digitalWrite(LED, LOW);
  } else {
    // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.println("Input Event : IN03 - Active!");
    delay(100);
  }
  if (buttonState2 == HIGH){
    digitalWrite(LED, LOW);
  } else {
    // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.println("Input Event : IN02 - Active!");
    delay(100);
  }
  if (buttonState1 == HIGH){
    digitalWrite(LED, LOW);
  } else {
    // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.println("Input Event : IN01 - Active!");
    delay(100);
  }

}
