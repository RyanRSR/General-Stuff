#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

int BW = 2;
int BG = 3;
int BR = 4;
int BY = 5;
int BB = 6;
int ledB = 8;
int ledY = 9;
int ledR = 10;
int ledG = 11;
int ledW = 12;

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

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
    Serial.println(F("Não foi possível começar:"));
    Serial.println(F("1. Por favor, verifique a conexão!"));
    Serial.println(F("2. Por favor, insira o cartão SD"));
    while (true) {
      delay(0);
    }
  }
  Serial.println(F("DFPlayer mini online"));
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BW) == LOW) {
    digitalWrite(ledW, HIGH);
    Serial.println("BW");
    myDFPlayer.play(1);
    delay(8000);
    digitalWrite(ledW, LOW);
  }


  if (digitalRead(BG) == LOW) {
    digitalWrite(ledG, HIGH);
    Serial.println("BW");
    myDFPlayer.play(2);
    delay(8000);
    digitalWrite(ledG, LOW);
  }


  if (digitalRead(BR) == LOW) {
    digitalWrite(ledR, HIGH);
    Serial.println("BW");
    myDFPlayer.play(3);
    delay(8000);
    digitalWrite(ledR, LOW);
  }


  if (digitalRead(BY) == LOW) {
    digitalWrite(ledY, HIGH);
    Serial.println("BW");
    myDFPlayer.play(4);
    delay(8000);
    digitalWrite(ledY, LOW);
  }


  if (digitalRead(BB) == LOW) {
    digitalWrite(ledB, HIGH);
    Serial.println("BW");
    myDFPlayer.play(5);
    delay(8000);
    digitalWrite(ledB, LOW);
  }
}

