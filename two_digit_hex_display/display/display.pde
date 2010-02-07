int latch_pin_1       = 2;
int latch_pin_2       = 3;
int display_pins[]    = {7,4,5,6};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(display_pins[i], OUTPUT);
  }
  pinMode(latch_pin_1, OUTPUT);
  pinMode(latch_pin_2, OUTPUT);
}

void loop() {
  
  int i = 0;
  
  for (i = 0; i < 100; i++) {
    set_number(i);
    delay(500);
  }
  
  i = 0;
}

void set_number(int number) {
  
  digitalWrite(latch_pin_2, LOW);
  digitalWrite(latch_pin_1, HIGH);
  
  if (number % 10 == 0) {
    digitalWrite(latch_pin_2, HIGH);
    digitalWrite(latch_pin_1, LOW);
    
    int first_digit = number / 10;
          
    for (int i = 0; i < 4; i++) {
      // read bits of $number sequentially by shifting it to right and & it with
      // 1. This results in either 0 or 1 and is written on the corresponding 
      // pin
      digitalWrite(display_pins[i], (first_digit >> i) & 0x01);
    }
    
    digitalWrite(latch_pin_2, LOW);
    digitalWrite(latch_pin_1, HIGH);
  }
  
  int second_digit = number % 10;
 
  for (int i = 0; i < 4; i++) {
    digitalWrite(display_pins[i], (second_digit >> i) & 0x01);
  }
  
  digitalWrite(latch_pin_1, HIGH);
  digitalWrite(latch_pin_2, HIGH);
}