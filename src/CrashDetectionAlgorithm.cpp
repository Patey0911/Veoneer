#include "CrashDetectionAlgorithm.h"
#include "EEPROM.h"
void CrashDetectionAlgorithm_Init();

void CrashDetectionAlgorithm_GetCrashType(char *mesaj_crashtype)
{
    //int cod;
    mesaj_crashtype=(char*)malloc(20*sizeof(char));
    //EEPROM.write(1,0);
    int k=0;
    if(accX<(-0.5))
    {
        k=1;
        const char mes[15]="BACK CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        //EEPROM.write(1,1);
    }
    else if(accX>0.5)
    {
        k=1;
        const char mes[15]="FRONT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        //EEPROM.write(1,2);
    }   
    if(accY>0.5)
    {
        k=1;
        const char mes[15]="LEFT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        //EEPROM.write(1,3);
    }
    else if(accY<(-0.5))
    {
        k=1;
        const char mes[15]="RIGHT CRASH";
        strcpy(mesaj_crashtype,mes);
        Serial.println(mesaj_crashtype);
        //EEPROM.write(1,4);
    }
    if(k==1)
    {
        delay(10000);
    }
    /*cod=EEPROM.read(1);
    if(cod>0)
    {
    Serial.println(cod);
    delay(10000);
    }
    */
}

void CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *);

void CrashDetectionAlgorithm_MainFunction();