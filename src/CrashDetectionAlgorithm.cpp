#include "CrashDetectionAlgorithm.h"
void CrashDetectionAlgorithm_Init();

void CrashDetectionAlgorithm_GetCrashType(char *mesaj_crashtype)
{
    mesaj_crashtype=(char*)malloc(20*sizeof(char));
    if(accX<(-0.5))
    {
        const char mes[15]="BACK CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        delay(10000);
    }
    else if(accX>0.5)
    {
        const char mes[15]="FRONT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        delay(10000);
    }   
    if(accY>0.5)
    {
        const char mes[15]="LEFT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        delay(10000);
    }
    else if(accY<(-0.5))
    {
        const char mes[15]="RIGHT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        delay(10000);
    }
}

void CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *);

void CrashDetectionAlgorithm_MainFunction();