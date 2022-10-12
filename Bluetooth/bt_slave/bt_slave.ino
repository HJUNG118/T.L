#include <SoftwareSerial.h>
SoftwareSerial HC06(2,3);
# define led 4
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HC06.begin(9600);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(HC06.available())
{
  char c = HC06.read();
  if( c == '0')
  {
    digitalWrite(led, LOW);
    HC06.write("led on");
  }
  else if( c == '1')
  {
    digitalWrite(led, HIGH);
    HC06.write("led off");
  }
}
}
