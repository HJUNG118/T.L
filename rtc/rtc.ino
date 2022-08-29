
#include "RTClib.h"

#include <Wire.h>
#include <stdio.h>


RTC_DS1307 rtc;




void setup() {
 Serial.begin(9600);


  if (! rtc.begin()) 
  {
    Serial.print("Couldn't fine RTC");
    while (1);
  }

  if (! rtc.isrunning())
  {
    Serial.println("RTC is NOT running, let's set the time!");
  }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));     

}

void loop() {

    DateTime now = rtc.now();
    unsigned int data = analogRead(A0);
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();                                                    //String(data)
                                                                           //string data =string(h)+","+string(t);
    
    Serial.println(String(data));
    


   
    delay(1000);
    

}
