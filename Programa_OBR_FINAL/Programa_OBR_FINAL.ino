#define IR_SENSOR_RIGHT 12
#define IR_SENSOR_MRIGHT 9
#define IR_SENSOR_MLEFT 10
#define IR_SENSOR_LEFT 11
#define MOTOR_SPEED 70
#define MOTOR_SPEED2 120

//Right motor
int enableRightMotor=2;
int rightMotorPin1=3;
int rightMotorPin2=4;

//Left motor
int enableLeftMotor=7;
int leftMotorPin3=6;
int leftMotorPin4=5;

void setup()
{
  //The problem with TT gear motors is that, at very low pwm value it does not even rotate.
  //If we increase the PWM value then it rotates faster and our robot is not controlled in that speed and goes out of line.
  //For that we need to increase the frequency of analogWrite.
  //Below line is important to change the frequency of PWM signal on pin D5 and D6
  //Because of this, motor runs in controlled manner (lower speed) at high PWM value.
  //This sets frequecny as 7812.5 hz.
  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin3, OUTPUT);
  pinMode(leftMotorPin4, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  pinMode(IR_SENSOR_MRIGHT, INPUT);
  pinMode(IR_SENSOR_MLEFT,INPUT);
  rotateMotor(0,0);   
}


void loop()
{

  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  int MidRIRSensorValue = digitalRead(IR_SENSOR_MLEFT);
  int MidLIRSensorValue = digitalRead(IR_SENSOR_MRIGHT);

  
  if (rightIRSensorValue == LOW & MidRIRSensorValue == LOW & leftIRSensorValue == LOW & MidLIRSensorValue == LOW )
  {
   rotateMotor(MOTOR_SPEED,MOTOR_SPEED);
  }
  //If right sensor detects black line, then turn right
  else if (rightIRSensorValue == LOW & MidRIRSensorValue == HIGH & leftIRSensorValue == LOW & MidLIRSensorValue == LOW )
  {
      rotateMotor(MOTOR_SPEED ,30); 
  }
  //If left sensor detects black line, then turn left  
  else if (rightIRSensorValue == LOW & MidRIRSensorValue == LOW & leftIRSensorValue == HIGH & MidLIRSensorValue == LOW )
  {
      rotateMotor(30, MOTOR_SPEED); 
  }
  else if (rightIRSensorValue == LOW & MidRIRSensorValue == LOW & leftIRSensorValue == HIGH & MidLIRSensorValue == HIGH){

    rotateMotor(MOTOR_SPEED2, 30);
  }
  else if(rightIRSensorValue == HIGH & MidRIRSensorValue == HIGH & leftIRSensorValue == LOW & MidLIRSensorValue == LOW){
    rotateMotor(30, MOTOR_SPEED2);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin3,HIGH);
    digitalWrite(leftMotorPin4,LOW);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin3,LOW);
    digitalWrite(leftMotorPin4,HIGH);      
  }
  else 
  {
    digitalWrite(leftMotorPin3,LOW);
    digitalWrite(leftMotorPin4,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
