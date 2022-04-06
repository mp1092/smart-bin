#include <Servo.h>   //servo library
Servo servo;
//Servo servo1;    
const int trigPin = 7;    
const int echoPin = 8;  
const int servoPin = 6;
//const int servoPin1 = 11;
const int trigPin1 =9;
const int echoPin1 = 10;
//int led= 10;
long duration,duration1,dist1,dist, average;  
//long aver[3];   //array for average


void setup() {      
    Serial.begin(9600);
    servo.attach(servoPin);
    //servo1.attach(servoPin1);
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);
    pinMode(trigPin1, OUTPUT);  
    pinMode(echoPin1, INPUT);
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
measure1();
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
Serial.print("Ultrasonic 1 : ");
Serial.println(dist);//obtain distance
if(dist<10)
{
  servo.write(0);
}
else
{
  servo.write(90);
}
}

void measure1() {  
 //digitalWrite(led,HIGH);
digitalWrite(trigPin1, LOW);
delayMicroseconds(5);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
dist1 = duration1/74/2;
Serial.print("Ultrasonic 2 : ");
Serial.println(dist1);
delay(1000);
}
