/*
  Blink EWM1.3c - ESP32
  Turns on an LED on for one second, then off for one second, repeatedly.

 created 2017
 by tech@esp8266-projects.com
*/

#define LED_BUILTIN 23  //LED on GPIO23

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
