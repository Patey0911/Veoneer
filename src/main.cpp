#include <Arduino.h>
#include <GlobalScheduler.h>

void setup() {
  
  Serial.begin(9600);
  TK_INIT();
}

void loop() {
  
  MainTaskScheduler();

}