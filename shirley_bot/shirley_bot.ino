
//motors attached directly to Arduino
//motor pins
int motorDirectionPin = 12;
int motorPwmPin = 3;
int motorBrakePin = 9;
//pump 1
int pump1DirectionPin = 13;
int pump1PwmPin = 11;
int pump1BrakePin = 8;

//pumps attached to motor driver
//pump 2 (left side)
int pump2pin1=2;
int pump2pin2=3;
//pump 3 (right side)
int pump3pin1=4;
int pump3pin2=5;

//boolean to switch direction
bool directionState;

void setup() {
  //define pins for motors
  //motor
  pinMode(motorDirectionPin, OUTPUT);
  pinMode(motorPwmPin, OUTPUT);
  pinMode(motorBrakePin, OUTPUT);
  //pump 1
  pinMode(pump1DirectionPin, OUTPUT);
  pinMode(pump1PwmPin, OUTPUT);
  pinMode(pump1BrakePin, OUTPUT);
  //pump 2
  pinMode(pump2pin1,OUTPUT);
  pinMode(pump2pin2,OUTPUT);
  //pump 3
  pinMode(pump3pin1,OUTPUT);
  pinMode(pump3pin2,OUTPUT);
}

void loop() {

  //rotate turntable

  rotateTurntable(1000);

  //activate first pump
  
  digitalWrite(pump1DirectionPin, HIGH);
  digitalWrite(pump1BrakePin, LOW);
  analogWrite(pump1PwmPin, 100);
  delay(1000); 
  digitalWrite(pump1BrakePin, HIGH);
  analogWrite(pump1PwmPin, 0);

  //rotate to next pump 

  rotateTurntable(1000);
  
  //activate second pump

  digitalWrite(pump2pin1, HIGH);
  delay(1000);
  digitalWrite(pump2pin1, LOW); 

  //rotate to final pump

  rotateTurntable(1000);

  //activate third pump

  digitalWrite(pump3pin2, HIGH);
  delay(1000);
  digitalWrite(pump3pin2, LOW); 

}

/** Rotates the turntable for the given number of ms */
void rotateTurntable(int ms) {

  digitalWrite(motorDirectionPin, HIGH);
  //release breaks
  digitalWrite(motorBrakePin, LOW);
  //set work duty for the pump1
  analogWrite(motorPwmPin, 60);

  delay(ms);  //rotate for this many ms

  //activate breaks
  digitalWrite(motorBrakePin, HIGH);
  //set work duty for the pump1 to 0 (off)
  analogWrite(motorPwmPin, 0);
}



