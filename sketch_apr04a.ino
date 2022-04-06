#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 7;    
int echoPin = 8;   
int servoPin = 6;
//int led= 10;
long duration, dist, average;   
//long aver[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
     
} 


void loop() { 
//  for (int i=0;i<=2;i++) {   //average distance
//    measure();               
//   aver[i]=dist;            
//    delay(1000);              //delay between measurements
//  }
// dist=(aver[0]+aver[1]+aver[2])/3;    
//
//if ( dist<20 ) {
////Change distance as per your need
// servo.attach(servoPin);
//  delay(1);
// servo.write(0);  
// delay(3000);       
// servo.write(180);    
// delay(1000);
// servo.detach();      
//}
//Serial.print(dist); 
measure();
}


void measure() {  
 //digitalWrite(led,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
dist = duration/74/2; 
Serial.println(dist);//obtain distance
if(dist<15)
{
  servo.write(0);
}
else
{
  servo.write(90);
}
}
