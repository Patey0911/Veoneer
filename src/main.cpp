#include <Arduino.h>
#include <GlobalScheduler.h>

//#define OUTPUT A0 //equivalent with pinMode(A0, OUTPUT);
#define LED_FRONT1 8 //front1
#define LED_FRONT2 7 //front2
#define LED_LEFT 6 //left
#define LED_RIGHT 5 //right

void setup() {

  pinMode(LED_FRONT1, OUTPUT);
  pinMode(LED_FRONT2, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);

  digitalWrite(LED_FRONT1, LOW);
  digitalWrite(LED_FRONT2, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);
    
  //pinMode(A0, OUTPUT); //pin for saleae
  Serial.begin(9600);
  TK_INIT();
}

void loop() {
  
  MainTaskScheduler();

}