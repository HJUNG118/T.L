#include<SoftwareSerial.h>
SoftwareSerial HC06(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  HC06.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
HC06.write('0');
delay(1000);
HC06.write('1');
delay(1000);

if(HC06.available())
{
  String inputStr = HC06.readStringUntil('\n');
  Serial.println(inputStr);
}
} 
