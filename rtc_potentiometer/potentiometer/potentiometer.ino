#include <Wire.h>
#include <stdio.h>



int potentiometer = A0;


void setup() {
 Serial.begin(9600);
    

}

void loop() {

    
    unsigned int pmValue = analogRead(potentiometer); // potentiometer=A0
    pmValue = map(pmValue, 0, 1023, 0, 180); // potentiometer -> pwm
    
       //String(data)

    Serial.println(pmValue);
                                                                           //string data =string(h)+","+string(t);
    delay(500);
    //Serial.println(String(data));
    


   
    

}
