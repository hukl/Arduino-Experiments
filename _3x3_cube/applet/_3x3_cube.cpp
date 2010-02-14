// DDRD
//  65432100
// B11111100

// DDRB
//    OMU
//  00LLL987
// B00111111

// 7 8 9
// 4 5 6
// 1 2 3 

#include "WProgram.h"
void setup();
void loop();
void setup() {
  DDRD = DDRD | B11111100;
  DDRB = DDRB | B00111111;
}

void loop() {
  // Frame 1
  PORTD = B00100100;
  PORTB = B00111001;
  delay(300);
  
  // Frame 2
  PORTD = (B00100100 << 1);
  PORTB = B00111010;
  delay(300);
  
  // Frame 3
  PORTD = (B00100100 << 2);
  PORTB = B00111100;
  delay(300);
  
  // Frame 4
  PORTD = (B00100100 << 1);
  PORTB = B00111010;
  delay(300);
  
  
  // Frame 5
  PORTD = B00100100;
  PORTB = B00111001;
  delay(300);

  // Frame 6
  PORTD = (B00100100 << 1);
  PORTB = B00111010;
  delay(300);
  
  // Frame 7
  PORTD = B01010000;
  PORTB = B00111001;
  delay(300);
  
  // Frame 8
  PORTD = B11100000;
  PORTB = B00111000;
  delay(300);
  
  // Frame 9
  PORTD = B01000100;
  PORTB = B00111100;
  delay(300);
  
  // Frame 10
  PORTD = B01001000;
  PORTB = B00111010;
  delay(300);
  
  // Frame 11
  PORTD = B01010000;
  PORTB = B00111001;
  delay(300);
  
  // Frame 8
  PORTD = B11100000;
  PORTB = B00111000;
  delay(100);
  
  // Frame 9
  PORTD = B01000100;
  PORTB = B00111100;
  delay(100);
  
  // Frame 10
  PORTD = B01001000;
  PORTB = B00111010;
  delay(100);
  
  // Frame 11
  PORTD = B01010000;
  PORTB = B00111001;
  delay(100);
  
  // Frame 8
  PORTD = B11100000;
  PORTB = B00111000;
  delay(100);
  
  // Frame 9
  PORTD = B01000100;
  PORTB = B00111100;
  delay(100);
  
  // Frame 10
  PORTD = B01001000;
  PORTB = B00111010;
  delay(100);
  
  // Frame 11
  PORTD = B01010000;
  PORTB = B00111001;
  delay(100);
  
  // Frame 8
  PORTD = B11100000;
  PORTB = B00111000;
  delay(100);
  
  // Frame 9
  PORTD = B01000100;
  PORTB = B00111100;
  delay(100);
  
  // Frame 10
  PORTD = B01001000;
  PORTB = B00111010;
  delay(100);
  
  // Frame 11
  PORTD = B01010000;
  PORTB = B00111001;
  delay(100);
  
  // Frame 8
  PORTD = B11100000;
  PORTB = B00111000;
  delay(1000);
  
  for (int i=0; i<150; i++) {
    // Frame 8
    PORTD = B11100000;
    PORTB = B00111000;
    delay(1);
    // Frame 8
    PORTD = B11111100;
    PORTB = B00010111;
    delay(1);
  }
  
  for (int i=0; i<75; i++) {
    // Frame 8
    PORTD = B00011100;
    PORTB = B00100111;
    delay(1);
    // Frame 8
    PORTD = B11100000;
    PORTB = B00010000;
    delay(1);
    
    PORTD = B00011100;
    PORTB = B00001111;
    delay(1);
  }
  
  for (int i=0; i<150; i++) {
    // Frame 8
    PORTD = B11100000;
    PORTB = B00111000;
    delay(1);
    // Frame 8
    PORTD = B11111100;
    PORTB = B00010111;
    delay(1);
  }
  
  for (int i=0; i<75; i++) {
    // Frame 8
    PORTD = B00011100;
    PORTB = B00100111;
    delay(1);
    // Frame 8
    PORTD = B11100000;
    PORTB = B00010000;
    delay(1);
    
    PORTD = B00011100;
    PORTB = B00001111;
    delay(1);
  }
  
  for (int i=0; i<150; i++) {
    // Frame 8
    PORTD = B11100000;
    PORTB = B00111000;
    delay(1);
    // Frame 8
    PORTD = B11111100;
    PORTB = B00010111;
    delay(1);
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

