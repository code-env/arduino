#include <AFMotor.h>

// Motor shield initialization
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// LDR sensor pins
const int ldrLeftPin = A5;
const int ldrRightPin = A2;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  
  // Set motor pins as outputs
  motor1.setSpeed(255); // Set the maximum speed for the motors
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  int ldrLeftValue = analogRead(ldrLeftPin); // Read the left LDR value
  int ldrRightValue = analogRead(ldrRightPin); // Read the right LDR value
  
  Serial.print("LDR Left Value: ");
  Serial.println(ldrLeftValue);
  Serial.print("LDR Right Value: ");
  Serial.println(ldrRightValue);

  int brightnessDifference = ldrLeftValue - ldrRightValue;

  // Adjust the threshold as needed based on your environment
  if (brightnessDifference > 50) {
    // If left is brighter than right by at least 50, turn left
    turnLeft();
  } else if (brightnessDifference < -50) {
    // If right is brighter than left by at least 50, turn right
    turnRight();
  } else {
    // Otherwise, move forward
    moveForward();
  }
  
  delay(100); // Delay for stability
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
