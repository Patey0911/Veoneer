#pragma once
#include<stdbool.h>

void GpsDriver_Init();

bool GpsDriver_GetPosition(float* , float*);

bool GpsDriver_GetDate(int*, char*, char*);

bool GpsDriver_IsProveoutComplete();

void GpsDriver_MainFunction();

bool GpsDriver_GetTime(char*, char*, char*);


