int pump = A0;
int moisturePin = D0;
// you can adjust the threshold value
int thresholdValue = 800;

void setup(){
  pinMode(moisturePin, INPUT);
  pinMode(pump, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  //the humidity and sensor values are inversely related

      //digital input code (thresholdValue is approx. 800
  bool moistureValue = digitalRead(moisturePin);
  Serial.print(moistureValue);
  if(moistureValue == true){
    Serial.println("Needs watering");
    analogWrite(pump, 255);
  }
  else
    Serial.println("Doesn't need watering");
  
   //analog input code  
    /*int sensorValue = analogRead(rainPin);
    Serial.println(sensorValue);
    if(sensorValue < thresholdValue){
    Serial.println(" - Doesn't need watering");
    //digitalWrite(redLED, LOW);
    //digitalWrite(greenLED, HIGH);
  }
  else {
    Serial.println(" - Time to water your plant");
    //digitalWrite(redLED, HIGH);
    //digitalWrite(greenLED, LOW);
  }*/
  
  delay(500);
}
