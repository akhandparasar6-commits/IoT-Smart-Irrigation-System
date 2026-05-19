// assigning names to the pins using define
#define sensorPin A0;  
#define relayPin D1;  

// variable declaration
int moistureValue;
int threshold = 700;   // Adjust based on calibration + Soil Type + sensor type

// setup() fxn runs only once 
// pin setup in this fxn
// serial comunication
void setup() {
  pinMode(relayPin, OUTPUT);  // because relay pin will send signals
  digitalWrite(relayPin, HIGH);   // Pump OFF initially
  Serial.begin(9600); // serial communication between PC and ESP32
}

// RUNS CONTINUOUSLY FOREVER
void loop() {

  // analogRead() -> analog to digital
  moistureValue = analogRead(sensorPin);  // moisture value store sensor data in digital form 
  
  // prints value on serial monitor
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  // decision making 
  if (moistureValue > threshold) {  
    Serial.println("Soil is Dry - Pump ON");
    digitalWrite(relayPin, LOW);    // Turn pump ON
  } 
  else {
    Serial.println("Soil is Wet - Pump OFF");
    digitalWrite(relayPin, HIGH);   // Turn pump OFF
  }

  delay(2000); // 2 sec break before next reading
}
