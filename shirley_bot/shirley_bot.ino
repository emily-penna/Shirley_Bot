
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

bool running = false;
int time = 2480;

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

  Serial.begin(9600);

}

void loop() {
  // Serial.println("Press any button to begin!");
  // while there is no input from the user, do nothing
  if (Serial.available() == 0 || running){
  }
  else {
    running = true;
    runCycle();
    running = false;
    Serial.read();
  }
}

void runCycle() {
  //rotate turntable
  rotateTurntable(time);

  delay(2000); //delay to adjust positions if needed

  //activate pumps
  //pump 1
  digitalWrite(pump1DirectionPin, HIGH);
  digitalWrite(pump1BrakePin, LOW);
  analogWrite(pump1PwmPin, 100);

  //pump 2
  digitalWrite(pump2pin1, HIGH);

  //pump 3
  // digitalWrite(pump3pin2, HIGH);

  delay(10000);


  //stop pumps
  //pump 1
  digitalWrite(pump1BrakePin, HIGH);
  analogWrite(pump1PwmPin, 0);

  //pump 2
  digitalWrite(pump2pin1, LOW); 

  //pump 3
  // digitalWrite(pump3pin2, LOW); 



}

/** Rotates the turntable for the given number of ms */
void rotateTurntable(int ms) {

  digitalWrite(motorDirectionPin, HIGH);
  //release breaks
  digitalWrite(motorBrakePin, LOW);
  //set work duty for the pump1
  //run at full speed
  analogWrite(motorPwmPin, 55);
  delay(ms/2); 

  //slow down
  analogWrite(motorPwmPin, 45);
  delay(ms/2);

  // digitalWrite(motorDirectionPin, LOW);
  // analogWrite(motorPwmPin, 45); 
  // delay(100);

  //activate breaks
  digitalWrite(motorBrakePin, HIGH);
  //set work duty for the pump1 to 0 (off)
  analogWrite(motorPwmPin, 0);
}




