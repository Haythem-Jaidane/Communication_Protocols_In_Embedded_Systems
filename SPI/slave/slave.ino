#include <SPI.h>

void setup()
{
  Serial.begin(115200);   
  SPI.begin();
  
  pinMode(53 , INPUT);
  pinMode(13,OUTPUT);
  SPCR  |= 0b11000000;
  SPSR  |= 0x00;
}  
 
void loop()
{
}
 
ISR(SPI_STC_vect)
{
    int received = SPDR;
    digitalWrite(13,1);
    Serial.println(received);
    if(received==1){
      digitalWrite(13,1);
      SPDR = 0b00000001;
    }
    else if(received==0){
      digitalWrite(13,0);
      SPDR = 0b00000000;
    }
}
