
#include <WiFi.h>
//#include "time.h"

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Font_Data.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   23
#define DATA_PIN  21
#define CS_PIN    22
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

#define DEBUG false

 
const char* ssid     = "xxxxxxxxxxxx";
const char* password = "xxxxxxxxxxxx";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 28801;//28800
const int   daylightOffset_sec = 0;

//time
  char timeWeekDay[10];
  char timeMonth[10];
  char timeDay[3];
  char timeYear[5];
  char timeHour[3];
  char timeMinute[3];
  char timeSecond[3];

  char timeAll[20];
  
void setup(){
   for(int i=0;i<20;i++)
     timeAll[i]=48;
    
  if(DEBUG)Serial.begin(115200);

  // Connect to Wi-Fi
  if(DEBUG)Serial.print("Connecting to ");
  if(DEBUG)Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if(DEBUG)Serial.print(".");
  }
  if(DEBUG)Serial.println("");
  if(DEBUG)Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  LocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  P.begin(3);
  P.setZone(0, 0, 3);
  P.setFont(0, numeric7Seg);
  P.setIntensity(1);//0-15
 }

void loop(){
  delay(1000);
  LocalTime();
    
   //P.displayText("Hello", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
   P.displayText(timeAll, PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
   P.displayAnimate();
   printTime();
  
}
  

void printTime(){
   
/*    Serial.print(timeWeekDay);Serial.print(", ");
    Serial.print(timeMonth);Serial.print(" ");
    Serial.print(timeDay);Serial.print(" ");
    Serial.print(timeYear);Serial.print(", ");
    Serial.print(timeHour);Serial.print(":");
    Serial.print(timeMinute);Serial.print(":");
    Serial.print(timeSecond);Serial.println();
 */
 
   for(int i=0;i<3;i++)
    timeAll[i]=timeHour[i];
    
    timeAll[2]=58;// :  http://www.asciitable.com/
    
   for(int i=0;i<3;i++){
    int j=i+3;
    timeAll[j]=timeMinute[i];
    }    
   timeAll[5]=58;// :
   
   for(int i=0;i<3;i++){
    int j=i+6;
    timeAll[j]=timeSecond[i];
    }    
    

 timeAll[8]='\0';
    
 if(DEBUG)Serial.println(timeAll);
 
 
 }

void LocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    if(DEBUG)Serial.println("Failed to obtain time");
    return;
  }
  //Tuesday, June 30 2020 15:14:45
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
 
  //Hour (12 hour format): 03
  //Serial.print("Hour (12 hour format): ");
  //Serial.println(&timeinfo, "%I");

  //timeWeekDay[10];
  //timeMonth[10];
  //timeDay[3];
  //timeYear[5];
  //timeHour[3];
  //timeMinute[3];
  //timeSecond[3];
  
    strftime(timeWeekDay,10, "%A", &timeinfo);
    strftime(timeMonth,10  , "%B", &timeinfo);
    strftime(timeDay,3     , "%d", &timeinfo);
    strftime(timeYear,5    , "%Y", &timeinfo);
    strftime(timeHour,3    , "%H", &timeinfo);
    strftime(timeMinute,3  , "%M", &timeinfo);
    strftime(timeSecond,3  , "%S", &timeinfo);
  /*
    Serial.println(timeWeekDay);
    Serial.println(timeMonth);
    Serial.println(timeDay);
    Serial.println(timeYear);
    Serial.println(timeHour);
    Serial.println(timeMinute);
    Serial.println(timeSecond);
    Serial.println();
  */
}

