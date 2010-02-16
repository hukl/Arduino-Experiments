// Arduino Pin / 74hc595 Pin
// 11 Data Serial In (14)
// 12 Storage register clock  (12)
// 13 Shift Register Clock    (11)

#include "WProgram.h"
void setup();
void loop();
int data_pin  = 11;
int latch_pin = 12;
int clock_pin = 13;

#define FRAME_COUNT 28

int frames[FRAME_COUNT][2] = {  {B00000011, B11111111},
                                {B00000101, B11111111},
                                {B00001001, B11111111},
                                {B00000101, B11111111},
                                {B00000011, B11111111},
                                {B00000101, B11111111},
                                {B00001001, B11111111},
                                {B00000101, B11111111},
                                {B00000010, B00000111},
                                {B00000010, B00000111<<3},
                                {B00000011, B11000000},
                                {B00000101, B11000000},
                                {B00000100, B00000111<<3},
                                {B00000100, B00000111},
                                {B00001000, B00000111},
                                {B00001000, B00000111<<3},
                                {B00001001, B11000000},
                                {B00001001, B11000000},
                                {B00001000, B00000111<<3},   
                                {B00001000, B00000111},      
                                {B00000100, B00000111},
                                {B00000100, B00000111<<3},
                                {B00000101, B11000000},
                                {B00000011, B11000000},
                                {B00000010, B00000111<<3},
                                {B00000010, B00000111},
                                {B00000010, B00111111},
                                {B00000011, B11111111}
                              };

void setup() {
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
}

void loop() {
  for (int f = 0; f < FRAME_COUNT; f++) {
    
    for (int i=0; i<50; i++) {
      digitalWrite(latch_pin, LOW);
      shiftOut(data_pin, clock_pin, MSBFIRST, frames[f][0]);
      shiftOut(data_pin, clock_pin, MSBFIRST, frames[f][1]);
      digitalWrite(latch_pin, HIGH);
      delayMicroseconds(1500);

      digitalWrite(latch_pin, LOW);
      shiftOut(data_pin, clock_pin, MSBFIRST, B00000000);
      shiftOut(data_pin, clock_pin, MSBFIRST, B00000000);
      digitalWrite(latch_pin, HIGH);
      delayMicroseconds(5);
    }
    
  }

}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

