#pragma once

void GsmDriver_Init();

void GsmDriver_TriggerSmsTransmission();

void GsmDriver_SetSmsData(char*);

void GsmDriver_MainFunction();

void GsmDriver_IsProveoutComplete();
