String a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
      delay(1);
      if(Serial.available()>0){
        a=Serial.readString(); 
        Serial.print(a);
      }
  }

}
