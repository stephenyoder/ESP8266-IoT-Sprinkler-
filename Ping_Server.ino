// Lab 8
// Exercise 2
// Ping a Server

#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

//ESP8266WiFiClass WiFi; take off the comment on the line below if not working 
//PingClass Ping;

// Enter WiFi Details
const char* ssid = "CBU-guest";
const char* password = "Lancers1";

// Website to ping
const char* remote_host = "www.google.com";

void setup() {
  
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected with IP ");  
  Serial.println(WiFi.localIP());

  Serial.print("Pinging host ");
  Serial.println(remote_host);

  if(Ping.ping(remote_host)) {
    Serial.println("Success");
  } else {
    Serial.println("Error");
  }
}

// Infinite Loop
void loop() { }
