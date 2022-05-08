#pragma once
#include<stdbool.h>

void GsmDriver_Init();

bool GsmDriver_TriggerSmsTransmission();

void GsmDriver_SetSmsData(char*, int);

void GsmDriver_MainFunction();

bool GsmDriver_IsProveoutComplete();

