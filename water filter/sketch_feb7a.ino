// /* Change these values based on your calibration values */
// int lowerThreshold = 420;
// int upperThreshold = 520;

// // Sensor pins
// #define sensorPower 7
// #define sensorPin A0

// // Value for storing water level
// int val = 0;

// // Declare pins to which LEDs are connected
// int redLED = 2;
// int yellowLED = 3;
// int greenLED = 4;

// void setup() {
// 	Serial.begin(9600);
// 	pinMode(sensorPower, OUTPUT);
// 	digitalWrite(sensorPower, LOW);
	
// 	// Set LED pins as an OUTPUT
// 	pinMode(redLED, OUTPUT);
// 	pinMode(yellowLED, OUTPUT);
// 	pinMode(greenLED, OUTPUT);

// 	// Initially turn off all LEDs
// 	digitalWrite(redLED, LOW);
// 	digitalWrite(yellowLED, LOW);
// 	digitalWrite(greenLED, LOW);
// }

// void loop() {
// 	int level = readSensor();

// 	if (level == 0) {
// 		Serial.println("Water Level: Empty");
// 		digitalWrite(redLED, LOW);
// 		digitalWrite(yellowLED, LOW);
// 		digitalWrite(greenLED, LOW);
// 	}
// 	else if (level > 0 && level <= lowerThreshold) {
// 		Serial.println("Water Level: Low");
// 		digitalWrite(redLED, HIGH);
// 		digitalWrite(yellowLED, LOW);
// 		digitalWrite(greenLED, LOW);
// 	}
// 	else if (level > lowerThreshold && level <= upperThreshold) {
// 		Serial.println("Water Level: Medium");
// 		digitalWrite(redLED, LOW);
// 		digitalWrite(yellowLED, HIGH);
// 		digitalWrite(greenLED, LOW);
// 	}
// 	else if (level > upperThreshold) {
// 		Serial.println("Water Level: High");
// 		digitalWrite(redLED, LOW);
// 		digitalWrite(yellowLED, LOW);
// 		digitalWrite(greenLED, HIGH);
// 	}
// 	delay(1000);
// }

// //This is a function used to get the reading
// int readSensor() {
// 	digitalWrite(sensorPower, HIGH);
// 	delay(10);
// 	val = analogRead(sensorPin);
// 	digitalWrite(sensorPower, LOW);

//   Serial.println(val);

// 	return val;
// }


const int sensorPin = A0; // Analog pin connected to the S (Signal) pin of the water sensor
const int sensorPowerPin = 7; // Digital pin connected to the VCC (+) pin of the water sensor
const float sensorMax = 1023.0; // Maximum sensor reading
const float waterMax = 1.0; // Maximum volume of water in liters (assuming the water sensor's range)

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(sensorPowerPin, OUTPUT); // Set sensor power pin as output
  digitalWrite(sensorPowerPin, HIGH); // Provide power to the sensor
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the sensor value
  
  // Convert the sensor value to liters using calibration
  float waterVolume = (sensorValue / sensorMax) * waterMax;
  
  // Print the water volume to the serial monitor
  Serial.print("Water Volume: ");
  Serial.print(waterVolume);
  Serial.println(" liters");
  
  delay(1000); // Delay for stability
}
