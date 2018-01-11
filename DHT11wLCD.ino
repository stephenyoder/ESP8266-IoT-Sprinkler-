// Lab 2 Exercise 2
// Temperature/Humidity on OLED Module

#include <dht.h>    // Library for DHT11 Temperature/Humidity Sensor

// Libraries for the Oled LCD LED Module
#include <Wire.h> 
#include <ACROBOTIC_SSD1306.h>

dht DHT;

#define DHT11_PIN 14   // Set Data Pin from Sensor

// Initialization
void setup()
{
  Serial.begin(9600);
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              // Set cursor position, start of line 0
  oled.putString("Read Sensor: ");
  oled.setTextXY(2,0);              // Set cursor position, start of line 2
  oled.putString("Humidity: ");
  oled.setTextXY(4,0);              // Set cursor position, start of line 4
  oled.putString("Temperature: ");
}

// Program Loop
void loop()
{
  int chk = DHT.read11(DHT11_PIN);   // Read Data Pin
  
  /*switch (chk)    // Handle Errors
  {
    case "OK": 
    oled.setTextXY(0,12);             
    oled.putString("OK");
    break;
    case "CHECKSUM": 
    oled.setTextXY(0,0);              
    oled.putString("Checksum error"); 
    break;
    case "TIMEOUT": 
    oled.setTextXY(0,0);              
    oled.putString("Time out error");
    break;
    default: 
    oled.setTextXY(0,0);              
    oled.putString("Unknown error"); 
    break;
  }*/

  // Print Humidity
  oled.setTextXY(2,9);    
  //float humidity = DHT.humidity;          
  oled.putString((String) DHT.humidity);
  oled.setTextXY(2,11);              
  oled.putString("%  ");

  // Print Temperature
  oled.setTextXY(4,12);      
  //float temperature = DHT.temperature;        
  oled.putString((String) DHT.temperature);
  oled.setTextXY(4,14);              
  oled.putString("C  ");

  // Wait 2000ms
  delay(2000);
}
//
// END OF FILE
//
