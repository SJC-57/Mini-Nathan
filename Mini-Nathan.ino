#include <Servo.h>

// Def notas musicales
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880

//Variable para el "dormir"
unsigned long  ultima_actividad = 0;
unsigned long tiempo_maximo = 20000;

//Variable para las canciones 
int canciones_tocadas = 0; 

//Variables para el giro
int angulo_actual = 90;
int direccion_giro = 1; 

//Variables para los millis
unsigned long ultimo_paso = 0; 
int intervalo_movimiento = 15;

//Pin del sensor táctil
int pin_touch = 4;

//Pines del ultrasonido
int pin_trigger = 2;
int pin_echo = 3;

//Pines extras
const int led = 7;
const int pin_buzzer = 9;

//Asignación de servos
Servo servo_horizontal;
Servo servo_vertical;

enum estado { 

  DORMIDO, 
  DESPIERTO, 
  INTERACTUANDO

};

estado estado_actual = DORMIDO;

// victory sound
void tocarCancion1() {
  int notas[] = { NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5 };
  int duraciones[] = { 150, 150, 150, 200, 200, 150, 150, 300 };

  for (int i = 0; i < 8; i++) {
    if (notas[i] == 0) {
      delay(duraciones[i]);
    } 

    else {
      tone(pin_buzzer, notas[i], duraciones[i]);
      delay(duraciones[i] * 1.30);
    }

  }
  noTone(pin_buzzer);
}

// star wars
void tocarCancion2() {
  int notas[] = { NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4 };
  int duraciones[] = { 300, 300, 300, 200, 100, 300, 200, 100, 400 };

  for (int i = 0; i < 9; i++) {
    tone(pin_buzzer, notas[i], duraciones[i]);
    delay(duraciones[i] * 1.30);
  }

  noTone(pin_buzzer);
}

// super mario bros
void tocarCancion3() {
  int notas[] = { NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 0, NOTE_G5 };
  int duraciones[] = { 100, 100, 100, 100, 100, 100, 100, 100, 200 };

  for (int i = 0; i < 9; i++) {
    if (notas[i] == 0) {
      delay(duraciones[i]);
    } 

    else {
      tone(pin_buzzer, notas[i], duraciones[i]);
      delay(duraciones[i] * 1.30);
    }
  }
  noTone(pin_buzzer);
}

void setup(){

  Serial.begin(9600); 
  pinMode(pin_touch, INPUT);
  pinMode(pin_echo, INPUT);
  pinMode(pin_trigger, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);

  servo_horizontal.attach(5);
  servo_vertical.attach(6);

  digitalWrite(led, LOW);
  servo_horizontal.write(90);
  servo_vertical.write(40);

}

void loop(){

  switch (estado_actual) {

    case DORMIDO:

      if (digitalRead(pin_touch) == HIGH) { 

        digitalWrite(led, HIGH);
        for (int angulo = 40; angulo <=90; angulo++){
          servo_vertical.write(angulo);
          delay(15);
        }
        
        ultima_actividad = millis();
        estado_actual = DESPIERTO;
      }

      break;
    
    case DESPIERTO:

      //PARA MIRAR ALREDEDOR

      if (millis() - ultimo_paso >= intervalo_movimiento) {
        ultimo_paso = millis();

        angulo_actual += direccion_giro;
        servo_horizontal.write(angulo_actual);

        if (angulo_actual >= 180) {
          direccion_giro = -1; //comienza a restar al ángulo
        }
        else if (angulo_actual <= 0) {
          direccion_giro = 1; //comienza a sumar al ángulo
        }
      }

      //PARA DETECTAR SI HAY ALGO

      digitalWrite(pin_trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(pin_trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(pin_trigger, LOW);

      long duracion = pulseIn(pin_echo, HIGH, 20000);
      long distancia = duracion*0.034/2;
      Serial.println(distancia);

      if (distancia > 2 && distancia < 50){

        estado_actual = INTERACTUANDO;
      }

      //PARA QUE SE "DUERMA"

      if (millis() - ultima_actividad >= tiempo_maximo) {

        tone(pin_buzzer, 392, 300);
        delay(150);
        tone(pin_buzzer, 261, 500);
        delay(300);
        noTone(pin_buzzer); 

        digitalWrite(led, LOW);

        for (int angulo = 90; angulo >= 40; angulo--) {
          servo_vertical.write(angulo);
          delay(20);
        }

        servo_horizontal.write(90);
        angulo_actual = 90;
        estado_actual = DORMIDO; 
      }

      //TOCAR MELODÍA 

      if (digitalRead(pin_touch) == HIGH) {
        
        canciones_tocadas++;

        if (canciones_tocadas > 3) {
          canciones_tocadas = 0;
        }

        if (canciones_tocadas == 0){
          
          tone(pin_buzzer, 220, 50);
          delay(50);
          noTone(pin_buzzer);
        }

        else if (canciones_tocadas == 1) {
          tocarCancion1();
        }

        else if (canciones_tocadas == 2) {
          tocarCancion2();
        }
        
        else if (canciones_tocadas == 3) {
          tocarCancion3();
        }
        
        delay(300); //para el rebote
        ultima_actividad = millis();

      }
      break;

    case INTERACTUANDO:

      delay(1000);

      tone(pin_buzzer, 523, 80);
      delay(100);
      tone(pin_buzzer, 659, 80);
      delay(100);
      tone(pin_buzzer, 784, 150);
      delay(150); 
      noTone(pin_buzzer);

      for (int i = 0; i < 2; i++) {
        servo_vertical.write(70);
        delay(100);
        servo_vertical.write(110);
        delay(100);
      }
      servo_vertical.write(90);
      delay(1000);

      ultima_actividad = millis();
      estado_actual = DESPIERTO;
      break; 

  }
}


