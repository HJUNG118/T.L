typedef struct _Record //struct

{

 

  int x; //4byte

  int y;

  int poten; //4

 

}Record;

 

void setup() {

 

Serial.begin(9600);

Serial.print("current");

Serial.print('\t');

Serial.print("voltage");

Serial.print('\t');

Serial.println("rpm");

 

pinMode(7, INPUT);

 

}

 

void loop() {

  

Record joy;

 

joy.x = analogRead(A0);

joy.y = analogRead(A1);

joy.poten = analogRead(A3);

 

 

Serial.print(joy.x);

Serial.print('\t');

Serial.print(joy.y);

Serial.print('\t');

Serial.println(joy.poten);

 

 

 

delay(1000);

}
