#pragma once

#include <MPU6050_light.h>
#include<MPU6500Driver.h>
#include<SystemStateManager.h>
#include<CrashReactionManager.h>

void CrashDetectionAlgorithm_Init();

void CrashDetectionAlgorithm_GetCrashType(char *);

void CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *);

void CrashDetectionAlgorithm_MainFunction();

