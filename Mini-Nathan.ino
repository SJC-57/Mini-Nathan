#include Servo.h
#include 

Servo cabeza;
int buzzer = 8;
int led = 7 
int a = 
int b = 
int c = 
int d = 
int e = 
int f = 
int g = 
  
void setup() {
  Serial.begin(9600)
  cabeza.attach(9);
  pinMode(led, OUTPUT);
  


}

void loop() {
  
  cabeza.write(0);
  delay(1000);
  cabeza.write(90);
  delay(1000);
  //prueba del servo

  tone(buzzer, 440)
  delay(500)
  noTone(buzzer);
  delay(500);
  //prueba del buzzer

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(500);






}
