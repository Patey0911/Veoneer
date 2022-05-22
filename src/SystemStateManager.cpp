#include "SystemStateManager.h"
char *actual_state=(char*)malloc(1);
void SystemStateManager_init()
{
    memcpy(actual_state,"0",1);
    //Serial.println(actual_state);
}

void SystemStateManager_GetSystemState(char *actual_state_p)
{
    memcpy(actual_state_p,actual_state,1);
    Serial.println(*actual_state_p);
    if(strcmp(actual_state_p,"1")==1)
    {
        Serial.println(*actual_state_p);
        delay(5000);
    }
}

void SystemStateManager_MainFunction()
{   
    if(returnSTATUS()==1)
    {
        memcpy(actual_state,"1",1);
    }
    SystemStateManager_GetSystemState(actual_state);
    memcpy(actual_state,"1",0);
   // Serial.println("da");
}