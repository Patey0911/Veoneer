#include <SoftwareSerial.h>
#include <Arduino.h>
#include "GsmDriver.h"
#include "CrashDetectionAlgorithm.h"
#include <string.h>

#define GSM_RX  2  
#define GSM_TX  3 
int nr;
SoftwareSerial sim(GSM_RX, GSM_TX);  //


String number = "+40725661830"; 
//String number = "+40765597414"; 
String SMS = "";

String convertToString(unsigned char* a, int size)
{
    int i;
    String s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

void GsmDriver_Init() {
 
  Serial.println("System Started...");
  sim.begin(115200);
  delay(1000);
  
 Serial.println("Communicating GSM/GPS.....");

    delay(1000);
    Serial.println("SMS set ready");   
}

void GsmDriver_SetSmsData(String sms_text){

    SMS = sms_text;
}

void GsmDriver_TriggerSmsTransmission()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");
  Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); 

  
  String crashtype_string, crashseverity_string;
  unsigned char* crash_type_gsm = CrashDetectionAlgorithm_GetCrashType(crash_type_gsm);
  unsigned char* crash_severity_gsm = CrashDetectionAlgorithm_GetCrashSeverity(crash_severity_gsm);  

  for(int i = 0; i < 12; i++){

    crashtype_string = crashtype_string + String(char(crash_type_gsm[i]));
    crashseverity_string = crashseverity_string + String(char(crash_severity_gsm[i]));

  }

  String sms_data = crashtype_string + "\n" + crashseverity_string;

  GsmDriver_SetSmsData(sms_data);


   nr=sim.println(SMS);
   Serial.println (nr);

  sim.println((char)26);// ASCII code of CTRL+Z
   
}


   
 
void GsmDriver_MainFunction(){

    GsmDriver_TriggerSmsTransmission();

}