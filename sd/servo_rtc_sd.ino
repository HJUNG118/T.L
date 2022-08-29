#include <SPI.h>

#include <SD.h>

#include"RTClib.h"

#include <Wire.h>

#include <stdio.h>

#include<Servo.h>

 

Servo servo;

RTC_DS1307 rtc;

const int chipSelect = 4;

 

 

 

// mosi 11, sck13, miso 12

 

 

void setup() {

 Serial.begin(9600);

 

 

  servo.attach(3); 

  servo.write(0);

 Serial.print("Initializing SD card..");           //SD카드 인식

     if (!SD.begin(chipSelect))  

     {

      Serial.println("Card failed. or not present");

      while  (1);

     }

      Serial.println("Card initialized.");

      delay(5000);   

  File dataFile = SD.open("y.txt", FILE_WRITE);

  dataFile.print("Time\t");

  dataFile.println("potentiometer");

  dataFile.close();

  

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

  File dataFile = SD.open("y.txt", FILE_WRITE);  //csv하면 엑셀 txt하면 메모장

  

  servo.attach(3); 

  servo.write(0);

  

  if (dataFile) 

  {

                                                                          

    dataFile.print(now.hour(), DEC);

    dataFile.print(':');

    dataFile.print(now.minute(), DEC);

    dataFile.print(':');

    dataFile.print(now.second(), DEC);

    dataFile.print("\t");                                                                       //unsigned int data = analogRead(A0);

 

    String str = Serial.readStringUntil('\n');

    int myInt = str.toInt();                                                              

    Serial.println(myInt);//string data =string(h)+","+string(t);

    servo.write(myInt);

    dataFile.println(myInt);

    dataFile.close();

 

 

  }

 

  else 

  {

    Serial.println("error opening test.txt");

  }

  

 

}
