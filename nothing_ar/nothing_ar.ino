#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

#define echoPin A0
#define trigPin A1
#define maximum_distance 200

int f_d, l_d, r_d;

NewPing sonar(trigPin, echoPin, maximum_distance);
Servo servo_motor;



AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);



void setup() {
  Serial.begin(9600);    // put your setup code here, to run once:
  motor1.setSpeed(150);  // Set the maximum speed for the motors
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
  servo_motor.attach(10);  //
  servo_motor.write(60);
}

void loop() {
  // put your main code here, to run repeatedly:

  turnServo();

  if(f_d > l_d && f_d > r_d){
    moveForward();
  }

}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

int calculatedDistance() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}


void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnServo()c {
  servo_motor.write(0);
  r_d = calculatedDistance();
  Serial.print("right: ");
  Serial.println(r_d);
  delay(2000);
  servo_motor.write(60);
  f_d = calculatedDistance();
  Serial.print("forward: ");
  Serial.println(f_d);
  delay(2000);
  servo_motor.write(120);
  l_d = calculatedDistance();
  Serial.print("left: ");
  Serial.println(l_d);
  delay(2000);
  servo_motor.write(60);
}