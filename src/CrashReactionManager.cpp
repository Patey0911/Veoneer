#include"CrashReactionManager.h"
#include"CrashDetectionAlgorithm.h"


unsigned char* crash_react_severity=NULL;
unsigned char* crash_react_type=NULL;
void CrashReactionManager_MainFunction()
{
    CrashDetectionAlgorithm_GetCrashType(crash_react_type);
    CrashDetectionAlgorithm_GetCrashSeverity(crash_react_severity);
    //Serial.println((char*)crash_react_type);
    //Serial.println((char*)crash_react_severity);

}