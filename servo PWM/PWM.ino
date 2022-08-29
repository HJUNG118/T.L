#include <Servo.h>

Servo servo;
int potPin = A0;
int val;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(potPin);
Serial.print("potentiometer = ");
Serial.println(val);
val = map(val, 0, 1023, 0, 179);
servo.write(val);
delay(50);

}
