// Pin configuration
const int trigPin = 9;  // Ultrasonic sensor trigger pin
const int echoPin = 10; // Ultrasonic sensor echo pin
const int relayPin = 8; // Relay module control pin
const int ledPin = 13;  // LED pin for visual indication

// Motor pump parameters
const int pumpRunTime = 5000; // Run the pump for 5 seconds

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Initially, turn off the pump
  digitalWrite(relayPin, HIGH);
}

void loop() {
  long duration, distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if someone is within a certain range (adjust as needed)
  if (distance < 10) {
    // Someone is close, turn on the tap
    digitalWrite(relayPin, LOW);
    digitalWrite(ledPin, HIGH); // LED on for visual indication

    // Run the pump for a specific duration
    delay(pumpRunTime);

    // Turn off the tap
    digitalWrite(relayPin, HIGH);
    digitalWrite(ledPin, LOW); // LED off
  }

  delay(1000); // Adjust the delay as needed for your application
}
