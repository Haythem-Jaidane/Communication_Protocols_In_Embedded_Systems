#include <SPI.h>

int count = 0;

void setup()
{
  DDRB |= 0x07;
  PORTB |= 0x01;
  SPCR |= 0x50;
  
  Serial.begin(115200);
  SPI.begin();
}
 
void loop()
{
  if(Serial.available()){
      char y=Serial.read();
      if(y=='o'){
        sendSerialData(1);
        delay(500);
      }
      else if(y=='f'){
        sendSerialData(0);
        delay(500);
      }
      
    }
}
 
void sendSerialData(int data)
{
  PORTB &= 0b11111110 ;
  delay(10);
  int receivedValue = SPI.transfer(data);
  Serial.println(receivedValue);
  PORTB |= 0x01;
}
