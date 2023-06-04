<<<<<<< HEAD
#include <Ultrasonic.h>
int esq, dir;
const int trigPin = 22; // defifnição do pino trigger
const int echoPin = 23; // definição do pino eco
const int maxDistance = 220; // distancia maxima que o sensor pode medir(em cm)

#define velmotor1 3
#define velmotor2 8
#define mot1a 4
#define mot1b 5
#define mot2a 6
#define mot2b 7
int vel=0;

void setup() {
  
  // put your setup code here, tont un once:
  pinMode(velmotor1,OUTPUT);
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, LOW);

  pinMode(velmotor2,OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot2b, LOW);
  
        
  digitalWrite(velmotor1, vel);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  pinMode(12,INPUT); // sensor esquerdo
  pinMode(13,INPUT); // sensor direito

}

void loop() {
  esq = digitalRead(12);
  dir = digitalRead(13);
  vel=255;
  analogWrite(velmotor1, vel);
  analogWrite(velmotor2, vel);

  
  if(esq == 0 and dir == 0){
    digitalWrite(mot1a, HIGH);
    digitalWrite(mot2a, HIGH);
  }
  if(esq == 1 and dir == 0){
    digitalWrite(mot1a, LOW);
    digitalWrite(mot2a, HIGH);
  }
  if(esq == 0 and dir == 1){
    digitalWrite(mot1a, HIGH);
    digitalWrite(mot2a, LOW);
  }
  if(esq == 1 and dir == 1){
    digitalWrite(mot1a, LOW);
    digitalWrite(mot2a, LOW);
  }

}
=======
#include <Ultrasonic.h>

const int trigPin = 22; // defifnição do pino trigger
const int echoPin = 23; // definição do pino eco
const int maxDistance = 220; // distancia maxima que o sensor pode medir(em cm)

#define velmotor 3
#define velmotor2 8
#define mot1a 4
#define mot1b 5
#define mot2a 6
#define mot2b 7
#define tmp 3000
int vel=0;

void setup() {
  // put your setup code here, tont un once:
  pinMode(velmotor,OUTPUT);
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, LOW);

  pinMode(velmotor2,OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot2b, LOW);
  
        
  digitalWrite(velmotor, vel);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  vel=255;
  analogWrite(velmotor, vel);

  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, HIGH);
  delay(tmp);

  digitalWrite(mla, LOW);
  digitalWrite(mlb, LOW);
  delay(100);

  digitalWrite(mla, HIGH);
  digitalWrite(mlb, LOW);
  delay(tmp);    
}
>>>>>>> a7a940d502f3c02c7162ed6250db6da36f4a16d6
