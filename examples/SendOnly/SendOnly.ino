/*
  Bonezegei Software Serial Send Only
  Author: Bonezegei (Jofel Batutay)
  Date: September 2023 

  Frame format: 8 bit word 1 Stop bit
  Do not use receive function when using send only mode
*/

#include <Bonezegei_SoftSerial.h>

/*
A Huge Thanks to JCWren on github for pointing this out
Send Only Mode
param1 =  RX pin (set to negative value to enable TX only mode)
param2 =  TX pin 
*/
Bonezegei_SoftSerial SoftSerial(-1 , 16);

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  SoftSerial.print("Hello World\n");
}


void loop() {
}
