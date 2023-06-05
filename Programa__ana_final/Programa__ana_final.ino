#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//INPUT
//Botões das cores (Nº indica porta do arduino)
int BW = 2;
int BG = 3;
int BR = 4;
int BY = 5;
int BB = 6;

//OUTPUT
//Luzes (Nº indica a porta)
int ledB = 8;
int ledY = 9;
int ledR = 10;
int ledG = 11;
int ledW = 12;

DFRobotDFPlayerMini myDFPlayer;
SoftwareSerial mySoftwareSerial(7, 13); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(BW, INPUT_PULLUP);
  pinMode(BG, INPUT_PULLUP);
  pinMode(BR, INPUT_PULLUP);
  pinMode(BY, INPUT_PULLUP);
  pinMode(BB, INPUT_PULLUP);
  pinMode(ledB, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledW, OUTPUT);

  if (!myDFPlayer.begin(mySoftwareSerial)) { // Use mySoftwareSerial to communicate with mp3.
    Serial.println("Não foi possível começar:");
    Serial.println("1. Por favor, verifique a conexão!");
    Serial.println("2. Por favor, insira o cartão SD");
  }else{
    Serial.println("DF player está online!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BW) == LOW) {
    digitalWrite(ledW, HIGH);
    Serial.println("BW");
    myDFPlayer.play("01.mp3");
    delay(8000);
    digitalWrite(ledW, LOW);
  }


  if (digitalRead(BG) == LOW) {
    digitalWrite(ledG, HIGH);
    Serial.println("BG");
    myDFPlayer.play("02.mp3");
    delay(8000);
    digitalWrite(ledG, LOW);
  }


  if (digitalRead(BR) == LOW) {
    digitalWrite(ledR, HIGH);
    Serial.println("BR");
    myDFPlayer.play("03.mp3");
    delay(8000);
    digitalWrite(ledR, LOW);
  }


  if (digitalRead(BY) == LOW) {
    digitalWrite(ledY, HIGH);
    Serial.println("BY");
    myDFPlayer.play("04.mp3");
    delay(8000);
    digitalWrite(ledY, LOW);
  }


  if (digitalRead(BB) == LOW) {
    digitalWrite(ledB, HIGH);
    Serial.println("BB");
    myDFPlayer.play("05.mp3");
    delay(8000);
    digitalWrite(ledB, LOW);
  }
}