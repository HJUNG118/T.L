#include <SPI.h>
#include <SD.h>
#include "RTClib.h"
#include <Wire.h>
#include <stdio.h>
#include<Servo.h>


const int chipSelect = 4;

// mosi 11, sck13, miso 12
Servo servo;

RTC_DS1307 rtc;
int sec = 0;
int min = 0;
int counter = 0;

String MyString;
String Parameter1= "VUASRL"; 
unsigned char Parameter2;
String Parameter3 = ".csv";


void setup() {
 Serial.begin(9600);
 
 Serial.println("Initializing SD card.."); 
 
 SD.begin(chipSelect) ; 
 
   rtc.begin();

   DateTime now = rtc.now();

   unsigned char Parameter2 = now.minute();
   
   MyString = Parameter1 + Parameter2 + Parameter3;
  
   File dataFile = SD.open(MyString, FILE_WRITE);

    dataFile.println(__TIME__);
    dataFile.print("Trust\t");
    dataFile.print("RPM\t");
    dataFile.print("Joy\t");
    dataFile.println("Time");
    dataFile.close();

    Serial.print("Trust\t");
    Serial.print("RPM\t");
    Serial.println("joy\t");

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
                 
  sec = millis()/1000-60*counter;
  if(sec == 60) { counter++;min++;}   

  servo.attach(A3); 
  servo.write(0);
  
 if(Serial.available())
 {
  File dataFile = SD.open(MyString, FILE_WRITE);  //csv하면 엑셀 txt하면 메모장

   if (dataFile) 
   {
    String str = Serial.readStringUntil('\n');                                                       
    Serial.print(str); // 넘어온 값 tap
    Serial.print('\t');
    
    int index1 = str.indexOf('\t');
    int inString1 = str.substring(0, index1).toInt(); //servo 구동값 int형으로 수
    inString1 = map(inString1, 0, 1023, 0, 180); //넘어온 저항값 PWM값으로 매

    servo.write(inString1);
    
    Serial.print(inString1); //servo 작동 
    Serial.print('\t'); //min, sec(timer)
    Serial.print(min);
    Serial.print("min");
    Serial.print(sec);
    Serial.print("sec");
    Serial.println();

    dataFile.print(str);
    dataFile.print("\t");                      //여기에 출력되는 값을 적어준다,.
    dataFile.print(min);
    dataFile.print(':');
    dataFile.println(sec);
    
    dataFile.close();

  }
 }

  else 
  {
    Serial.println("error opening VUASRL.csv");
  }
  delay (1000);

}
