
#include <WiFi.h>
#include "time.h"


const char* ssid     = "xxxxxxxxxxxx";
const char* password = "xxxxxxxxxxxx";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

void setup(){
  Serial.begin(115200);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(){
  delay(1000);
  printLocalTime();
}

void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  //Tuesday, June 30 2020 15:14:45
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
 

  //Hour (12 hour format): 03
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");

  //Serial.println("Time variables");
  //char timeHour[3];
  //strftime(timeHour,3, "%H", &timeinfo);
  //Serial.println(timeHour);
  //char timeWeekDay[10];
  //strftime(timeWeekDay,10, "%A", &timeinfo);
  //Serial.println(timeWeekDay);
  Serial.println();
}
