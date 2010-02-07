int redVal   = 255; // Variables to store the values to send to the pins
int greenVal = 1;   // Initial values are Red full, Green and Blue off
int blueVal  = 1;

int redPin   = 9;   // Red LED,   connected to digital pin 9
int greenPin = 10;  // Green LED, connected to digital pin 10
int bluePin  = 11;  // Blue LED,  connected to digital pin 11

int i = 0;
int wait = 50;

void setup() {
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);
}

void loop() {
  
  i += 1;      // Increment counter
   if (i < 255) // First phase of fades
   {
     redVal   -= 1; // Red down
     greenVal += 1; // Green up
     blueVal   = 1; // Blue low
   }
   else if (i < 509) // Second phase of fades
   {
     redVal    = 1; // Red low
     greenVal -= 1; // Green down
     blueVal  += 1; // Blue up
   } 
   else if (i < 763) // Third phase of fades
   {
     redVal  += 1; // Red up
     greenVal = 1; // Green low
     blueVal -= 1; // Blue down
   }
   else // Re-set the counter, and start the fades again
   {
     i = 1;
   }
   
   analogWrite(redPin,   redVal);   // Write current values to LED pins
   analogWrite(greenPin, greenVal); 
   analogWrite(bluePin,  blueVal);
   
   delay(50);
}
