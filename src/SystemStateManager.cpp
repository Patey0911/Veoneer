#include "SystemStateManager.h"
char *actual_state=NULL;
void SystemStateManager_init()
{
    *actual_state=NULL;
}

void SystemStateManager_GetSystemState(char *actual_state_p)
{
    SystemStateManager_MainFunction();
  actual_state_p=actual_state;
  if(actual_state!=NULL)
    {
        Serial.println(actual_state);
    }
}

void SystemStateManager_MainFunction()
{ 
    if(returnSTATUS()==1)
    {
        actual_state=(char*)malloc(sizeof(1));
        memcpy(actual_state,"1",1);
        SystemStateManager_GetSystemState(actual_state);
    }
}