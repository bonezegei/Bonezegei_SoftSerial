/*
  This Library is written for Software Serial
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  8 bit word 1 Stop bit
*/

#ifndef _BONEZEGEI_SOFTSERIAL_H_
#define _BONEZEGEI_SOFTSERIAL_H_
#include <Arduino.h>

class Bonezegei_SoftSerial {
public:

  Bonezegei_SoftSerial();
  Bonezegei_SoftSerial(int rx, int tx);
  Bonezegei_SoftSerial(int rx);

  void begin(int baud);

  void write(char ch);
  void print(const char *ch);
  void println(const char *ch);
  void print(String str);
  void println(String str);

  char available();
  int read();

  int _rx;
  int _tx;

  int _baud;
  double timeInterval;
  uint32_t timeMS;
};


#endif
