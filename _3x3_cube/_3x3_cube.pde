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

void setup() {
  DDRD = DDRD | B11111100;
  DDRB = DDRB | B00111111;
}

void loop() {
  
  PORTD = B00100100;
  PORTB = B00100001;
  delayMicroseconds(100);
  
  PORTD = B00100100;
  PORTB = B00010001;
  delayMicroseconds(100);
  
  PORTD = B00100100;
  PORTB = B00001001;
  delayMicroseconds(100);

}



// 20mA bei 2.044V    an 5V bei 150 Ohm

// 7.35 mA bei 1,46V  an 4.65V bei 100 Ohm