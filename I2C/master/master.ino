#include <Wire.h>

char c;
int value;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    c=Serial.read();
    Wire.beginTransmission(8);
    Wire.write(c);
    Wire.endTransmission();
  }
  delay(500);
}
