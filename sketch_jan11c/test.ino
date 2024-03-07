const int soundSensorPin = A0; // Analog pin connected to the sound sensor
const int relayPin = 9; // Digital pin connected to the LED

void setup() {
  pinMode(soundSensorPin, INPUT); // Set sound sensor pin as input
  pinMode(relayPin, OUTPUT); // Set LED pin as output
}

void loop() {
  // Read the analog voltage from the sound sensor
  int soundValue = analogRead(soundSensorPin);
  
  // Adjust the threshold as needed based on your environment
  if (soundValue > 500) { // If sound level is above threshold (clap detected)
    digitalWrite(relayPin, HIGH); // Turn on the LED
    delay(200); // Delay to debounce the clap
  } else { // If sound level is below threshold (no sound)
    digitalWrite(relayPin, LOW); // Turn off the LED
  }
  
  delay(100); // Delay for stability
}
