/*
  This Library is written for Software Serial
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/
#include "Bonezegei_SoftSerial.h"


Bonezegei_SoftSerial::Bonezegei_SoftSerial() {
}

Bonezegei_SoftSerial::Bonezegei_SoftSerial(int rx, int tx) {
  _rx = rx;
  _tx = tx;
  //TX mode
  if (rx < 0) {
    pinMode(_tx, OUTPUT);
    digitalWrite(_tx, HIGH);
  } else {
    pinMode(_rx, INPUT_PULLUP);
    pinMode(_tx, OUTPUT);
    digitalWrite(_tx, HIGH);
  }
}

Bonezegei_SoftSerial::Bonezegei_SoftSerial(int rx){
  _rx = rx;
  pinMode(_rx, INPUT_PULLUP);
}

void Bonezegei_SoftSerial::begin(int baud) {
  _baud = baud;
  timeInterval = (1.0 / (float)baud);
  timeMS = (uint32_t)(timeInterval * 1000000);
}

void Bonezegei_SoftSerial::write(char ch) {
  digitalWrite(_tx, LOW);
  delayMicroseconds(timeMS);
  for (int a = 0; a < 8; a++) {
    if (ch & (1 << a)) {
      digitalWrite(_tx, HIGH);
    } else {
      digitalWrite(_tx, LOW);
    }
    delayMicroseconds(timeMS);
  }
  digitalWrite(_tx, HIGH);
  delayMicroseconds(timeMS);
}

void Bonezegei_SoftSerial::print(const char *ch) {
  while (*ch) {
    write(*ch);
    ch++;
  }
}

void Bonezegei_SoftSerial::println(const char *ch) {
  while (*ch) {
    write(*ch);
    ch++;
  }
  write('\n');
}

void Bonezegei_SoftSerial::print(String str){
  print(str.c_str());
}

void Bonezegei_SoftSerial::println(String str){
  println(str.c_str());
}

char Bonezegei_SoftSerial::available() {
  int x = digitalRead(_rx);
  if (x) {
    return 0;
  } else {
    return 1;
  }
}

int Bonezegei_SoftSerial::read() {

  int ch = 0;
  for (int a = 0; a < 9; a++) {
    if (digitalRead(_rx)) {
      ch |= (1 << a);
    }
    delayMicroseconds(timeMS);
  }
  digitalWrite(_rx, HIGH);
  return ch >> 1;
}
