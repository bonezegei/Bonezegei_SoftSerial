/*
  Bonezegei Software Serial
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  Frame format: 8 bit word 1 Stop bit

  Simple Send and Receive
  NOTE : the Receive function is not interrupt based 
         use separate device for Uart receiver or transmitter
*/


#include <Bonezegei_SoftSerial.h>

/*
param1 =  RX
param2 =  TX
*/
Bonezegei_SoftSerial SoftSerial(16, 15);

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  SoftSerial.println("UART Test");
}


void loop() {
  if (SoftSerial.available()) {
    int ch = SoftSerial.read();
    Serial.write(ch);
  }
  if (Serial.available()) {
    int ch = Serial.read();
    SoftSerial.write(ch);
  }
}
