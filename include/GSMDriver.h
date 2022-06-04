#pragma once
#include<stdbool.h>
#include<gsm_a6.h>

void GsmDriver_Init();

bool GsmDriver_TriggerSmsTransmission();

void GsmDriver_SetSmsData();

void GsmDriver_MainFunction();

bool GsmDriver_IsProveoutComplete();

