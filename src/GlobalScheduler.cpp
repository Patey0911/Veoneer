#include "GlobalScheduler.h"
#include "MPU6500Driver.h"

unsigned long int timerTK2=0, timerTK1=0, timerTK3=0;

void TK_1(){

}

void TK_3(){

}

void TK_INIT(){     //used in setup()

    MPU6500Driver_Init();
}

void TK_2(){

    MPU6500Driver_MainFunction();
}

void MainTaskScheduler(void){   //used in loop()

    if (micros() - timerTK2 > 500)
  {
    TK_2();
    timerTK2 = micros();
  }
  if (micros() - timerTK3 > 1000)
  {
    TK_3();
    timerTK3 = micros();
  }
  if (micros() - timerTK1 > 5000)
  {
    TK_1();
    timerTK1 = micros();
  }
}