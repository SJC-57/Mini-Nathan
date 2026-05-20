#include <Servo.h>


Servo cabeza;
int i = 0;
int buzzer = 8;
int led = 7;
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 9;
int f = 10;
int g = 11;
  
void setup() {
  Serial.begin(9600);
  cabeza.attach(9);
  pinMode(led, OUTPUT);

}

void loop() {

  for (i = 0; i <= 180; i ++){
    cabeza.write(i);
    delay(20);
  }

  for (i = 180;  i >= 0; i --){
    cabeza.write(i);
    delay(20);
  }
  //prueba del servo

  tone(buzzer, 440);
  delay(500);
  noTone(buzzer);
  delay(500);
  //prueba del buzzer

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(500);
  //prueba del led








}
