#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "url for your firebase project"                         // the project name address from firebase id
#define FIREBASE_AUTH "Your Firebase secret key"                    // the secret key generated from firebase

const char* ssid = "Your Wifi SSID";// 
const char* password = "Your Wifi Password";
String fireStatus = "";    

void setup()
{
  Serial.begin(115200);
  delay(10);
  pinMode(D1, OUTPUT);
  digitalWrite(D1, 0);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  Serial.print(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("LED", "\"OFF\"");   
 }
void loop()
{
fireStatus = Firebase.getString("LED");                                      // get led status input from firebase
      {
        if (fireStatus == "\"ON\"") 
        {  
        digitalWrite(D1, HIGH);
        }
        else if (fireStatus == "\"OFF\"")
        {  
        digitalWrite(D1, LOW);
        }
        else 
        {
        Serial.println("Wrong Credential! Please send ON/OFF");
        }
      }
}

 
 
