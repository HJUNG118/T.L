#define led 13

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  
  Serial.println("Hello coordinator");
  delay(1000);
      
}
