#pragma once
#include "MPU6050_light.h"
#include "MPU6500Driver.h"
#include <SystemStateManager.h>
#include "CrashDetectionAlgorithm.h"

void CrashReactionManager_Init();

void CrashReactionManager_MainFunction();

void CrashReactionManager_GetDeploymentMask(unsigned char *);

