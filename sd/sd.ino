#include <SPI.h>
#include <SD.h>

#include <Wire.h>
#include <stdio.h>

const int chipSelect = 4;
// mosi 11, sck13, miso 12


void setup() {
 Serial.begin(9600);

 Serial.print("Initializing SD card..");           //SD카드 인식
     if (!SD.begin(chipSelect))  
     {
      Serial.println("Card failed. or not present");
      while  (1);
     }
      Serial.println("Card initialized.");
      
  delay(5000);
   

}

void loop() {
  File dataFile = SD.open("text.txt", FILE_WRITE);  //csv하면 엑셀 txt하면 메모장
  if (dataFile) 
  {
                                                                          
                                                                           //unsigned int data = analogRead(A0);
                                                                         //String(data)
    String ch = Serial.readStringUntil('\n'); 
    Serial.println(ch);//string data =string(h)+","+string(t);
    dataFile.print(ch);//
    dataFile.close();


  }

  else 
  {
    Serial.println("error opening test.txt");
  }
  

}
