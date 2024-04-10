#include <Arduino.h>

// Defina os pinos para o sensor TCS3200
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

//pinos de controle dos motores de mesmo PWM
#define MOTOR_A_IN1 3 // D3
#define MOTOR_A_IN2 9 // D5
#define MOTOR_B_IN1 10 // D6
#define MOTOR_B_IN2 11 // D9

//define o valor pra cada cor nos pinos
#define red 0
#define green 1
#define blue 2


unsigned int rgb[] = {0,0,0};


void setup() {
  Serial.begin(9600);
  
  // Configuração dos pinos do sensor TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Configuração dos pinos da ponte H
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);
  
  // Inicialmente, ambos os relés estão desligados
  // motor 1: parar
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  //motor 2: parar
  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, LOW);
}

void loop() {
  // Lê os valores RGB
  readRGB();
  
  // Decide a ação com base nos valores RGB
  decideAction();
  
  delay(50); // Pode ajustar este delay conforme necessário
}

void readRGB() {
  // Lê o valor vermelho
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  rgb[red] = pulseIn(sensorOut, LOW);
  delay(10);

  // Lê o valor verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  rgb[green] = pulseIn(sensorOut, LOW);
  delay(10);

  // Lê o valor azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  rgb[blue] = pulseIn(sensorOut, LOW);
  delay(10);

  // Imprime os valores RGB no monitor serial
  Serial.print("R: ");
  Serial.print(rgb[red]);
  Serial.print("\tG: ");
  Serial.print(rgb[green]);
  Serial.print("\tB: ");
  Serial.println(rgb[blue]);
}

void decideAction() {
  if (rgb[red] < 60 && rgb[green] > 90 && rgb[blue] > 60) {
    // Vermelho: Vai para a direita
    // motor 1: ligar
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    //motor 2: parar
    digitalWrite(MOTOR_B_IN1, LOW);
    digitalWrite(MOTOR_B_IN2, LOW);

    delay(700);  // Vira por 500ms. Ajuste conforme necessário.

    // motor 1: ligar
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    //motor 2: ligar
    digitalWrite(MOTOR_B_IN1, HIGH);
    digitalWrite(MOTOR_B_IN2, LOW);
    delay(10);
  } 
  else if (rgb[red] > 50 && rgb[green] < 50 && rgb[blue] < 60) {
    // Verde: Vai para frente
    // motor 1: ligar
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    //motor 2: ligar
    digitalWrite(MOTOR_B_IN1, HIGH);
    digitalWrite(MOTOR_B_IN2, LOW);
  } 
  else if (rgb[red] > 80 && rgb[green] > 50 && rgb[blue] < 60) {
    // Azul: Vai para a esquerda
    // motor 1: parar
    digitalWrite(MOTOR_A_IN1, LOW);
    digitalWrite(MOTOR_A_IN2, LOW);
    //motor 2: ligar
    digitalWrite(MOTOR_B_IN1, HIGH);
    digitalWrite(MOTOR_B_IN2, LOW);

    delay(700);  // Vira por 500ms. Ajuste conforme necessário.
    
    // motor 1: ligar
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    //motor 2: ligar
    digitalWrite(MOTOR_B_IN1, HIGH);
    digitalWrite(MOTOR_B_IN2, LOW);
    delay(10);
  } 
  else if (rgb[red] > 150 && rgb[green] > 145 && rgb[blue] > 100) {
  // Preto: Parar
  // motor 1: parar
  digitalWrite(MOTOR_A_IN1, 0);
  digitalWrite(MOTOR_A_IN2, 0);
  //motor 2: parar
  digitalWrite(MOTOR_B_IN1, 0);
  digitalWrite(MOTOR_B_IN2, 0);
  }
}


