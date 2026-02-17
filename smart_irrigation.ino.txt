#define sensorPin A0
#define relayPin D1

int moistureValue;
int threshold = 700;   // Adjust based on calibration

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);   // Pump OFF initially
  Serial.begin(9600);
}

void loop() {

  moistureValue = analogRead(sensorPin);
  
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {  
    Serial.println("Soil is Dry - Pump ON");
    digitalWrite(relayPin, LOW);    // Turn pump ON
  } 
  else {
    Serial.println("Soil is Wet - Pump OFF");
    digitalWrite(relayPin, HIGH);   // Turn pump OFF
  }

  delay(2000);
}
