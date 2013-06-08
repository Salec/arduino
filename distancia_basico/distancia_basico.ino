/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 More info at: http://goo.gl/kJ8Gl
 */

#include <stdio.h>
#include <stdlib.h>


int tigers[] ={37,36};
int echos[] ={35,34};
int numBombilla[]={3,5};
int count=2;
int countBom=2;
int ledPin[]={9,10};
int numLed=3;
int light=200;

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
   for(int i = 0; i< countBom; i++)
  {
    pinMode(numBombilla[i],OUTPUT);
  }
    
}


void loop() {

  int distancia1, distancia2;
  distancia(echos[0],tigers[0],&distancia1);
  distancia(echos[1],tigers[1],&distancia2);
  
 
  if (distancia1 > distancia2){
    enciendeLed(ledPin[0]);
  }
  
 if (distancia1 < distancia2){
    enciendeLed(ledPin[1]);
  }
    Serial.print("Valores: ");
    Serial.print(distancia1);
    Serial.print("--------Valor 2---------");
    Serial.println(distancia2);
    Serial.print("Valor de la luz ");
    Serial.println(light);
    for(int i =distancia1;i >= 0;i--)
    {
      Serial.print(i);
      analogWrite(numBombilla[0], min(distancia1-i,170)); //me aseguro que no pasa de 170 por si quemo el circuito
      delay(10);
    }
    for(int i =distancia2;i >= 0;i--)
    {
      Serial.print(i);
      analogWrite(numBombilla[1], min(distancia2-i,170)); //me aseguro que no pasa de 170 por si quemo el circuito
      delay(10);
    }
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
