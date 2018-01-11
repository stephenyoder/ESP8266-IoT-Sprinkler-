// Lab 2 Exercise 1
// Temp/Humidity Sensor
/*
#include <dht11.h>   // Library for DHT11 Temperature/Humidity Sensor

dht11 DHT11;

#define DHT11PIN 14   // Set Data Pin from Sensor (Pin D5)

void setup()
{
  Serial.begin(115200);   // Set Serial Transfer Rate
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.println();
}

void loop()
{
  Serial.println("\n");   // New Line

  int chk = DHT11.read(DHT11PIN);   // Read Data Pin

  Serial.print("Read Sensor: ");
  
  switch (chk)    // Handle Errors
  {
    case DHTLIB_OK: 
    Serial.println("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.println("Checksum error"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.println("Time out error"); 
    break;
    default: 
    Serial.println("Unknown error"); 
    break;
  }

  // Print Humidity to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(String(DHT11.humidity));
  Serial.println("%");

  // Print Temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(String(DHT11.temperature));
  Serial.println("C");

  // Wait 2000ms
  delay(2000);
}*/
//
// END OF FILE
//

/*
#include "DHT11.h"
#define dht_apin 14 // Analog Pin sensor is connected to
 
DHT11 DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.setup(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.getHumidity());
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.getTemperature()); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() */

#include <dht.h>

dht DHT;

#define DHT11_PIN 14 

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print("C  ");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%  ");
  delay(1000);
}
