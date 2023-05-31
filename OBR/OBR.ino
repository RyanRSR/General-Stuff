`#include <AFMotor.h>
#include <Ultrasonic.h>

const int trigPin = 22; // defifnição do pino trigger
const int echoPin = 23; // definição do pino eco
const int maxDistance = 220; // distancia maxima que o sensor pode medir(em cm)

AF_DCMotor motor1A(1);

void setup() {
// put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

}

void loop() {
// put your main code here, to run repeatedly:
long duration, distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration / 2 / 29.1;

motor1A.setSpeed(100);
motor1A.run(FORWARD);
if (distance >= 20){
motor1A.setSpeed(0);
}
}`