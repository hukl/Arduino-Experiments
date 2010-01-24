int poti_pin = 0;
int poti_val = 0;

void setup() {  
  Serial.begin(9600);
}

void loop() {
  poti_val = analogRead(poti_pin);

  Serial.print(poti_val);
}