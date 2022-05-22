#include "SystemStateManager.h"
char *actual_state=NULL;
void SystemStateManager_init()
{
    actual_state=(char*)malloc(15);
    strcpy(actual_state,"0");
}

void SystemStateManager_GetSystemState(char *actual_state_p)
{
    SystemStateManager_MainFunction();
  //actual_state_p=actual_state;
  if(strcmp(actual_state_p,"1"))
    {
        Serial.println(*actual_state_p);
    }
}

void SystemStateManager_MainFunction()
{ 
    if(returnSTATUS()==true)
    {
        actual_state=(char*)malloc(sizeof(1));
        memcpy(actual_state,"1",1);
    }
    SystemStateManager_GetSystemState(actual_state);
}