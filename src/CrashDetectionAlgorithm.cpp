#include "CrashDetectionAlgorithm.h"
void CrashDetectionAlgorithm_Init();

void CrashDetectionAlgorithm_GetCrashType(char *mesaj_crashtype)
{
    mesaj_crashtype=(char*)malloc(20*sizeof(char));
    float accX, accY, accZ;
    MPU6500Driver_GetAccelerationData(&accX, &accY, &accZ);
    if(accX<(-1))
    {
        const char mes[15]="BACK CRASH";
        strcpy(mesaj_crashtype,mes);
    }
    if(accX>1)
    {
        const char mes[15]="FRONT CRASH";
        strcpy(mesaj_crashtype,mes);
    }   
}

void CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *);

void CrashDetectionAlgorithm_MainFunction();