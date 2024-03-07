#include <AFMotor.h>
#include <Servo.h>

#define Speed 180
#define Trig A0
#define Echo A1
#define spoint 90
#define MIN_DISTANCE 12
#define LEFT_ANGLE 20
#define RIGHT_ANGLE 150
#define TURN_DELAY 500
#define BACKUP_DELAY 100
#define STOP_DELAY 200
#define TURN_SPEED 150

int distance;
int Left;
int Right;
unsigned long previousTime = 0;
unsigned long currentTime = 0;

Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  servo.attach(10);
  start();
  setMotorSpeed();
  Serial.begin(9600);
}

void loop() {
  currentTime = millis();
  distance = ultrasonic();
  if (distance <= MIN_DISTANCE) {
    Stop();
    backward();
    if (currentTime - previousTime >= BACKUP_DELAY) {
      previousTime = currentTime;
      int L = leftsee();
      servo.write(spoint);
      delay(TURN_DELAY);
      int R = rightsee();
      servo.write(spoint);
      if (L < R) {
        turnleft();
      } else if (L > R) {
        turnright();
      }
    }
  } else {
    forward();
  }
}

void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void turnleft() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void turnright() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

int leftsee() {
  servo.write(LEFT_ANGLE);
  delay(TURN_DELAY);
  Left = ultrasonic();
  return Left;
}

int rightsee() {
  servo.write(RIGHT_ANGLE);
  delay(TURN_DELAY);
  Right = ultrasonic();
  return Right;
}

int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  long cm = t / 29 / 2;
  return cm;
}

void start() {
  delay(3000);
  for (int a = 0; a < 4; a++) {
    servo.write(spoint);
    delay(50);
    servo.write(LEFT_ANGLE);
    delay(50);
    servo.write(RIGHT_ANGLE);
    delay(50);
    servo.write(spoint);
  }
}

void setMotorSpeed() {
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
}
