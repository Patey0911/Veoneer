#pragma once

void GsmDriver_Init();

void GsmDriver_TriggerSmsTransmission();

void GsmDriver_SetSmsData(char*, int);

void GsmDriver_MainFunction();

void GsmDriver_IsProveoutComplete();