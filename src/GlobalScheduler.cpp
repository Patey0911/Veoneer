#include "GlobalScheduler.h"

unsigned long int timerTK2 = 0, timerTK1 = 0, timerTK3 = 0; //order of priorities
char*state=NULL;

void TK_INIT()
{     //used in setup()
    MPU6500Driver_Init();
    SystemStateManager_init();
    CrashDetectionAlgorithm_Init();
}

void TK_1()
{

}

void TK_2()
{
    MPU6500Driver_MainFunction();
    CrashDetectionAlgorithm_MainFunction();
    CrashReactionManager_MainFunction();
}

void TK_3()
{
  SystemStateManager_GetSystemState(state);
  CrashDataRecorder_MainFunction();
  //NvmManager_MainFunction();
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