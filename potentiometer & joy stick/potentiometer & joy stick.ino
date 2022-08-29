#include <Wire.h>
#include <stdio.h>

int potentiometer = A0;
int joy = 7;
typedef struct _Record //struct

{

  int x; //4byte
  int y;
  int poten; //4

}Record;

void setup() {

Serial.begin(9600);
pinMode(joy, INPUT);

}

 

void loop() { 

Record joy;

joy.x = analogRead(A1);
joy.y = analogRead(A2);
joy.poten = analogRead(A0);
//joy.poten = map(joy.poten, 0, 1023, 0, 180); // potentiometer -> pwm
    

Serial.print(joy.poten);
Serial.print('\t');
Serial.print(joy.y);
Serial.print('\t');
Serial.print(joy.x);
Serial.print("\n");


delay(1000);

}
