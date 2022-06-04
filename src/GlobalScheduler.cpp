#include "GlobalScheduler.h"
#include "MPU6500Driver.h"
#include "CrashDetectionAlgorithm.h"
#include "CrashReactionManager.h"
#include "SystemStateManager.h"
#include "GsmDriver.h"

unsigned long int timerTK2 = 0, timerTK1 = 0, timerTK3 = 0; //order of priorities

void TK_1(){


  if(returnSTATUS() == 1){
    GsmDriver_MainFunction();
    setSTATUS();
  }

  
}

void TK_3(){

}

void TK_INIT(){     //used in setup()

    MPU6500Driver_Init();
    SystemStateManager_init();
    CrashDetectionAlgorithm_Init();
    GsmDriver_Init();
}

void TK_2(){

    //digitalWrite(A0, 1);  //digitalWrite for saleae
    MPU6500Driver_MainFunction();
    //digitalWrite(A0, 0);
    CrashDetectionAlgorithm_MainFunction();
    CrashReactionManager_MainFunction();
}

void MainTaskScheduler(void){   //used in loop()

    
  if (micros() - timerTK2 > 500)
  {
    TK_2();
    timerTK2 = micros();
    //Serial.println("TK_2");
  }

  if (micros() - timerTK3 > 1000)
  {
    TK_3();
    timerTK3 = micros();
    //Serial.println("TK_3");
  }

  if (micros() - timerTK1 > 5000)
  {
    TK_1();
    timerTK1 = micros();
    //Serial.println("TK_1");
  }


}