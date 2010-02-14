
#define FRAME_COUNT 68
#define REAL_FRAME_COUNT (FRAME_COUNT * 2)

#include "WProgram.h"
void setup();
void calculate_frames(uint8_t* frames);
void loop();
uint8_t frames[FRAME_COUNT] = { B00110011, B11001100, B11110000, B00001111, \
                                B11000011, B00111100, B11001100, B01100110, \
                                B00110011, B00010001, B00100010, B00100001, \
                                B11001100, B11000011, B11110000, B00111100, \
                                B00001111, B00010100, B00101000, B01000001, \
                                B10000010, B00010100, B00101000, B01000001, \
                                B10000010, B00010100, B00101000, B01000001, \
                                B10000010, B00010100, B00101000, B01000001, \
                                B00110011, B00111100, B00001111, B00110011, \
                                B11110000, B11000011, B00110011, B00111100, \
                                B00000000, B11111111, B00000000, B11111111, \
                                B11110000, B00001111, B11001111, B11110011, \
                                B11110000, B11000011, B00110011, B00111100,
                                B11111111, B11111111, B00000000, B00000000,
                                B11111111, B11111111, B11111111, B11111111,
                                B00000000, B11111111, B11111111, B11111111,
                                B00000000, B11111111, B00000000, B00000000 };
                      
uint8_t level_1 = B00000100;
uint8_t level_2 = B00001000;
uint8_t real_frames[REAL_FRAME_COUNT];

void setup() {

  // Only write on Pins 2-7 as 0-1 are rx and tx
  DDRD = DDRD | B11111100;

  calculate_frames(frames);
}

void calculate_frames(uint8_t* frames) {

  uint8_t j = 0;
  for (int i = 0; i < FRAME_COUNT; i++) {
    
    uint8_t f = frames[i];
    real_frames[j] = (f & B11110000) | level_1 ;
    j += 1;
    real_frames[j] = (f << 4) | level_2 ;
    j += 1;
    
  }
}
void loop() {
  
  uint8_t t = 1;
  
  for (int f=0; f < REAL_FRAME_COUNT; f+=2, t+=2) {
    
    for (int i=0; i<50; i++) {
      PORTD = real_frames[f];
      delay(1);
      PORTD = real_frames[t];
      delay(1);
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

