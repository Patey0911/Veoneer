#include "CrashDetectionAlgorithm.h"
#include "EEPROM.h"

void CrashDetectionAlgorithm_Init();

void CrashDetectionAlgorithm_GetCrashType(char *mesaj_crashtype)
{

}

void CrashDetectionAlgorithm_GetCrashSeverity(char *mesaj_severity)
{

    //0.7 low
    //1 high
}

void CrashDetectionAlgorithm_MainFunction()
{
    //int cod;
    char *mesaj;
    mesaj=(char*)malloc(20*sizeof(char));
    int k=0;
    if(return_accx()>0.7)
    {
        k=1;
        const char mes[8]="FRONT";
        strcpy(mesaj,mes);
    } 
    if(return_accy()>0.7)
    {
        k=1;
        const char mes[8]="LEFT";
        strcpy(mesaj,mes);
    }
    else if(return_accy()<(-0.7))
    {
        k=1;
        const char mes[8]="RIGHT";
        strcpy(mesaj,mes);
    }
    if(k==1)
    {
        if(return_accx()>1||return_accy()<(-1)||return_accy()>1)
        {
            
        }
        Serial.println(mesaj);
        delay(10000);
    }
}