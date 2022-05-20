#include "CrashDetectionAlgorithm.h"
#include "MPU6500Driver.h"

float accX_crash, accY_crash, accZ_crash;
unsigned char* crash_type=NULL;
unsigned char* crash_severity=NULL;

void CrashDetectionAlgorithm_Init()
{

}


void CrashDetectionAlgorithm_MainFunction()
{
    MPU6500Driver_GetAccelerationData(&accX_crash, &accY_crash, &accZ_crash);
    if(accX_crash>0.7)
    {
        crash_type=(unsigned char*)malloc(sizeof(12));
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"FRONT CRASH",12);
        }
    }
    if(accY_crash>0.7)
    {
        crash_type=(unsigned char*)malloc(sizeof(12));
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"RIGHT CRASH",12);
        }
    }
    else if(accY_crash<(-0.7))
    {
        crash_type=(unsigned char*)malloc(sizeof(11));
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"LEFT CRASH",11);
        }
    }
    if(accX_crash>1||accY_crash>1||accY_crash<(-1))
    {
        crash_severity=(unsigned char*)malloc(sizeof(11));
        if(!crash_severity)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_severity,"HIGH CRASH",11);
        }
    }
    else if(accX_crash>0.7||accY_crash>0.7||accY_crash<(-0.7))
    {
        crash_severity=(unsigned char*)malloc(sizeof(10));
        if(!crash_severity)
        {
            Serial.println("ERROR!");
        }
        else{
            memcpy(crash_severity,"LOW CRASH",10);
        }
    }
}

void CrashDetectionAlgorithm_GetCrashType(unsigned char* crash_type_p)
{
    crash_type_p=crash_type;
}

void CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *crash_severity_p)
{
    crash_severity_p=crash_severity;
}

