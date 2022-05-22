#pragma once
#include <MPU6050_light.h>
#include "CrashReactionManager.h"
#include "CrashDetectionAlgorithm.h"

void SystemStateManager_init();

void SystemStateManager_GetSystemState(char *);

void SystemStateManager_MainFunction();
