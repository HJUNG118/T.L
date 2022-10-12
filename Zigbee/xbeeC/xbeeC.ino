#define button 13

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int buttonState = digitalRead(button);

if(Serial.available())
{
  if(buttonState == 0)
    {
       Serial.println("Hello router);
       delay(1000);
    }d

}
