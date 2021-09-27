#include <Wire.h>

char g;

void setup() {
  DDRB |= 0x80;
  
  Wire.begin(8);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  Wire.onRequest(RequestEvent);
  Wire.onReceive(ReceiveEvent);
}

void loop() {
}

void ReceiveEvent(int n_byte){
    g=Wire.read();
    if(g=='o'){
      PORTB |= 0x80; 
    }
    else if(g=='f'){
      PORTB &= 0x00;
    }
}
