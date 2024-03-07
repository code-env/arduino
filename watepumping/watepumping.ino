#include <NewPing.h>  //Ultrasonic sensor function library. You must install this library



int echoPin = 7;
int trigPin = 6;
int waterPin = 5;
int relayPin = 4;
int soundPin = 3;
int turbityPin = A1;
int waterAnaloguePin = A0;
int max_distance = 100;
int ntu, read_ADC;

int distance = 100;

NewPing sonar(trigPin, echoPin, max_distance);


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(soundPin, OUTPUT);
  pinMode(turbityPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(soundPin, LOW);
  digitalWrite(relayPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  read_ADC = analogRead(turbityPin);


  distance = readPing();
  if (read_ADC > 208) read_ADC = 208;

  ntu = map(read_ADC, 0, 208, 300, 0);

  if (ntu < 10) Serial.println("Water Very Clean");
  if (ntu >= 10 && ntu < 30) Serial.println("Water Norm Clean");
  if (ntu >= 30) Serial.println("Water Very Dirty");

  if (distance <= 5) {
    digitalWrite(soundPin, HIGH);
    delay(500);
    // digitalWrite(soundPin, LOW);
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(soundPin, LOW);
    digitalWrite(relayPin, HIGH);
  }


  delay(500);
}


int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}