#pragma once
#include "MPU6500Driver.h"
#include "CrashDataRecorder.h"
#include "MPU6500Driver.h"
#include "CrashDetectionAlgorithm.h"
#include "CrashReactionManager.h"
#include "SystemStateManager.h"
#include "NVMManager.h"

void TK_INIT();

void MainTaskScheduler(); 

void TK_1();

void TK_2();

void TK_3();

