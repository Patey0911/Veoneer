#include"CrashReactionManager.h"
#include"CrashDetectionAlgorithm.h"


unsigned char* crash_react;
void CrashReactionManager_MainFunction()
{
    CrashDetectionAlgorithm_GetCrashSeverity(crash_react);
    
}