#define sensorPin 8
#define relayPin 9

// Variable to store the time when last event happened
unsigned long lastEvent = 0;
boolean relayState = false;    // Variable to store the state of relay

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay pin as an OUTPUT pin
  pinMode(sensorPin, INPUT);  // Set sensor pin as an INPUT
}

void loop() {
  // Read Sound sensor
  int sensorData = digitalRead(sensorPin);

  // If pin goes LOW, sound is detected
  if (sensorData == LOW) {

    // If 25ms have passed since last LOW state, it means that
    // the clap is detected and not due to any spurious sounds
    if (millis() - lastEvent > 50) {
      //toggle relay and set the output
      relayState = !relayState;
      digitalWrite(relayPin, relayState ? HIGH : LOW);
    }

    // Remember when last event happened
    lastEvent = millis();
  }
}