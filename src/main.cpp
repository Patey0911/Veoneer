#include <Arduino.h>
#include <GlobalScheduler.h>
#include"GSMDriver.h"
//GSMSim gsm;

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  TK_INIT();
  
 
    GsmDriver_Init();
}

void loop() {
  
  GsmDriver_SetSmsData();

}

 




