#include <Servo.h>. 
int tPin = 2;
int ePin = 3;
int buz = 10;
int d1,d2;
int i =0;
int sdistance;
Servo myServo; 
void setup() {
  Serial.begin(9600);
  pinMode(tPin, OUTPUT); 
  pinMode(ePin, INPUT); 
  pinMode(buz,OUTPUT);
  myServo.attach(9); 
}
void loop() {
  for(i=0;i<=180;i += 10)
  {  
  myServo.write(i);
  delay(30);
  d2 = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(d2); 
  Serial.print(".");
  }
 
  for(i=180;i>0; i-=10){  
  myServo.write(i);
  delay(30);
  d2 = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(d2);
  Serial.print(".");
  }
}
int calculateDistance(){ 
  
  digitalWrite(tPin,HIGH); 
  delay(1000);
  digitalWrite(tPin, LOW);
  d1 = pulseIn(ePin, HIGH); 
  d2 = d1 * 0.0171821306;
  if (d2 < 10)
    {
      digitalWrite(buz,HIGH);
             
    }
    else
    {
      digitalWrite(buz,LOW);
    }
     return d2;
}
