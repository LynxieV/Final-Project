#include <ESP8266WiFi.h>
#include "Gsender.h"
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
/*
   This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
float homelat = 47.605895;
float homelng = -122.332143;
static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;

//counting emails sent
int emails = 0;

// The TinyGPS++ object
TinyGPSPlus gps;


// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

#pragma region Globals
const char* ssid = "EY wavespace";                           // WIFI network name
const char* password = "S0ciety@920";                       // WIFI network password
uint8_t connection_state = 0;                    // Connected to WIFI or not
uint16_t reconnect_interval = 10000;             // If not connected wait time to try again
#pragma endregion Globals

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword); 
        Serial.println(nSSID);
    } else {
        WiFi.begin(ssid, password);
        Serial.println(ssid);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}

//number of emails sent to address
  while(emails <  1 || emails > 1){
  }
    //need to change var name/make var for emails (to count)
    if(emails == 3){
      break;
      }
      else{
       conu
      }
  }
    }

void displayInfo()
{ 
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid()){
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else{
    Serial.print(F("INVALID"));
  }
}

// needed so robot sends only 2 emails
// with a delay of ?? minutes (TBD)
//void email_time(){
//  add while loop
//}
//
//void time(){
//}

void setup()
{

    Serial.begin(115200);
    ss.begin(GPSBaud);
    
    if((homelat <= 47.605181) || (homelat >= 0)){//47.605955)) {
       connection_state = WiFiConnect();
      if(!connection_state)  // if not connected to WIFI
         Awaits();          // constantly trying to connect

// Ask Lynxie about bottom code 
    if((homelng <= -122.332000) || (homelat >= -122.331000)) {
      Serial.begin(115200);
      connection_state = WiFiConnect();
      if(!connection_state)  // if not connected to WIFI
         Awaits();          // constantly trying to connect
      Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
         String subject = "ALERT, YOUR FAMILY MEMBER HAS LEFT THE SAFE ZONE";
      if(gsender->Subject(subject)->Send("safeandsoundgwc@gmail.com", "The Safe and Sound GPS is outside of your set safe zone. Your family member's current location is: " + String(gps.location.lat(), 6) + String(gps.location.lng(), 6))) {
         Serial.println("Message sent.");
      } else {
         Serial.print("Error sending message: ");
         Serial.println(gsender->getError());
      }
    }
}

    
void loop(){
  num_emails ();
  if((gps.location.isValid())){
  if((homelat <= 47.605181) || (homelat >= 0)){//47.605955)) {
       // constantly trying to connect
      Gsender *gsender = Gsender::Instance();    // Getting pointer to class instance
       String subject = "Alert! Your family member has left the Safe Zone.";
      if(gsender->Subject(subject)->Send("safeandsoundgwc@gmail.com", "The Safe and Sound GPS is outside of your set safe zone. Your family member's current location is: Latitude: " + String(gps.location.lat(), 6) + "Longitude: " + String(gps.location.lng(), 6))) {
         Serial.println("Message sent.");
         emails ++;
      } else if {
         Serial.print("Error sending message: ");
         Serial.println(gsender->getError());
      }
       Serial.print("test" + String(gps.location.lat(), 6));
      // This sketch displays information every time a new sentence is correctly encoded.
      while (ss.available() > 0)
        if (gps.encode(ss.read()))
        displayInfo();
        }
      if (millis() > 5000 && gps.charsProcessed() < 10){
      Serial.println(F("No GPS detected: Check wiring."));
      }
}
