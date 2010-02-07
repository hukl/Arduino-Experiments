
uint8_t frames[12] = { B00110011, B11001100, B11110000, B00001111, \
                      B11000011, B00111100, B11001100, B01100110, \
                      B00110011, B00010001, B00100010, B00100001 };
                      
uint8_t level_1 = B00000100;
uint8_t level_2 = B00001000;
uint8_t real_frames[24];

void setup() {

  // Only write on Pins 2-7 as 0-1 are rx and tx
  DDRD = DDRD | B11111100;

  Serial.begin(9600);

  calculate_frames(frames);
}

void calculate_frames(uint8_t* frames) {

  // die beiden schleifen kann man jetzt auch zusammen werfen
  uint8_t j = 0;
  for (int i=0; i<12; i++) {
    uint8_t f = frames[i]; // hier ist es braun ... frames[i] mit i > 3 ist ganz schlecht
    real_frames[j] = (f & B11110000) | level_1 ;
    j += 1;
    real_frames[j] = (f << 4) | level_2 ;
    j += 1;
  }
}
void loop() {
  
  uint8_t t = 1;
  
  for (int f=0; f<23; f+=2, t+=2) {
    
    for (int i=0; i<100; i++) {
      PORTD = real_frames[f];
      delay(1);
      PORTD = real_frames[t];
      delay(1);
    }
  }
}