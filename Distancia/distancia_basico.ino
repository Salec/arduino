/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 More info at: http://goo.gl/kJ8Gl
 */

#include <stdio.h>
#include <stdlib.h>


int tigers[] ={12,36};
int echos[] ={13,34};
int count=2;
int ledPin[]={9,10,11};
int numLed=3;

void setup() {
  Serial.begin (9600);
  for(int i = 0; i< count; i++)
  {
    pinMode(tigers[i],INPUT);
        pinMode(tigers[i],OUTPUT);
  }
 for(int i = 0; i< numLed; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
    
}


void loop() {

  int distancia1, distancia2;
  distancia(echos[0],tigers[0],&distancia1);
    distancia(echos[1],tigers[1],&distancia2);
  
  if(distancia1 ==0 || distancia2 ==0 || distancia1==distancia2)
  {
    enciendeLed(ledPin[1]);
  }
  if (distancia1 > distancia2){
    enciendeLed(ledPin[0]);
  }
  
 if (distancia1 < distancia2){
    enciendeLed(ledPin[2]);
  }
    Serial.print("Valores: ");
    Serial.print(distancia1);
    Serial.print("--------Valor 2---------");
    Serial.println(distancia2);
    
  
  delay(500);
}
void distancia(int echo, int disparador,int *distance)
{
  
  int duration;
  digitalWrite(disparador, HIGH);
  delayMicroseconds(1000);
  digitalWrite(disparador, LOW);
  duration=   pulseIn(echo, HIGH);
  *distance=((duration/2) / 29.1);
  
}
void enciendeLed(int a)
{
   digitalWrite(a,HIGH);
   delay(100);
   digitalWrite(a,LOW);
  
}
