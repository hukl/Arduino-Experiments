//**************************************************************//
//  Name    : shiftOutCode, Hello World                                 //
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis  //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;


#define FRAME_COUNT 40
byte data_array[FRAME_COUNT] = { B10000001, B11000011, B11100111, B11111111, \
                                 B11111111, B11100111, B11000011, B10000001, \
                                 B00000000, B10000000, B11000000, B11100000, \
                                 B11110000, B11111000, B11111100, B11111110, \
                                 B11111111, B11111110, B11111100, B11111000, \
                                 B11110000, B11100000, B11000000, B10000000, \
                                 B00000000, B01000000, B00100000, B00010000, \
                                 B00001000, B00000100, B00000010, B00000100, \
                                 B00001000, B00010000, B00100000, B01000000, \
                                 B10000000, B10000001, B10000001, B00000000 };


void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < FRAME_COUNT; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, data_array[i]);
    digitalWrite(latchPin, HIGH);
    delay(80);
  }
  
}
