#include <Arduino.h>
#include <GlobalScheduler.h>


void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  TK_INIT();
}

void loop() 
{
  MainTaskScheduler();
}

 




