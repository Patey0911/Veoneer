#include "CrashDetectionAlgorithm.h"
#include "MPU6500Driver.h"

float accX_crash, accY_crash, accZ_crash;
unsigned char* crash_type = NULL;
unsigned char* crash_severity = NULL;
unsigned long int timp1=0,timp2=0;
int ISCRASH=0;

void CrashDetectionAlgorithm_Init()
{
    crash_severity=NULL;
    crash_type=NULL;
    ISCRASH=0;
}

void CrashDetectionAlgorithm_MainFunction()
{
    unsigned long int k = 0;
    MPU6500Driver_GetAccelerationData(&accX_crash, &accY_crash, &accZ_crash);
    //Serial.println(accX_crash);
    if(millis()-timp1>10000)
    {
    if(accX_crash>0.6)
    {
        timp1=millis();
        crash_type=(unsigned char*)malloc(12);
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"FRONT CRASH",12);
        }
    }
    if(accY_crash>0.9)
    {   
        timp1 = millis();
        crash_type=(unsigned char*)malloc(12);
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"RIGHT CRASH",12);
        }
    }
    else if(accY_crash<(-0.9))
    {   timp1 = millis();
        crash_type=(unsigned char*)malloc(11);
        if(!crash_type)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_type,"LEFT CRASH",11);
        }
    }
    }

    if(millis()-timp2>10000)
    {
    if(accX_crash>1.4||accY_crash>1.4||accY_crash<(-1.4))
    {
        k=1;
        timp2=millis();
        crash_severity=(unsigned char*)malloc(11);
        if(!crash_severity)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_severity,"HIGH CRASH",11);
        }
    }
    else if(accX_crash>0.9||accY_crash>0.9||accY_crash<(-0.9))
    {   
        timp2 = millis();
        k=1;
        crash_severity=(unsigned char*)malloc(10);
        if(!crash_severity)
        {
            Serial.println("ERROR!");
        }
        else
        {
            memcpy(crash_severity,"LOW CRASH",10);
        }
        }
    }
    
    if(k==1)
    {
        ISCRASH=1;
        Serial.println((char*)crash_type);
        Serial.println((char*)crash_severity);
        Serial.println();
    }
}

// void CrashDetectionAlgorithm_GetCrashType(unsigned char* crash_type_p)
// {
//     crash_type_p=crash_type;
// }

unsigned char* CrashDetectionAlgorithm_GetCrashType(unsigned char* crash_type_p)
{
    crash_type_p=crash_type;
    return crash_type_p;
}

unsigned char* CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *crash_severity_p)
{
    crash_severity_p=crash_severity;
    return crash_severity_p;
}

int returnSTATUS()
{
    return ISCRASH;
}

void setSTATUS()
{
    ISCRASH=0;
}