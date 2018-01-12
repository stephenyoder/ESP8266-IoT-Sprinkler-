// Connecting to WiFi

#include <ESP8266WiFi.h>

// Enter WiFi Details
const char* ssid = "CBU-guest";
const char* password = "Lancers1";

void setup() {
  
  Serial.begin(115200);
  delay(2000);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());   // Print IP Address of the board
}

// Infinite Loop
void loop() {
  }
