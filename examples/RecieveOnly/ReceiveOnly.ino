/*
  Bonezegei Software Serial Recieve Only
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  Frame format: 8 bit word 1 Stop bit

  NOTE : the Receive function is not interrupt based 
         use separate device for Uart receiver or transmitter
*/


#include <Bonezegei_SoftSerial.h>

/*
param1 =  RX
Receive pin declaration
DO NOT use the write functions like write, print and println since the pin for write is not properlty initialized
*/
Bonezegei_SoftSerial SoftSerial(16);

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  
}


void loop() {
  if (SoftSerial.available()) {
    int ch = SoftSerial.read();
    Serial.write(ch);
  }
}
