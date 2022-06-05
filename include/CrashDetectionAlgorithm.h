#pragma once

void CrashDetectionAlgorithm_Init();

unsigned char* CrashDetectionAlgorithm_GetCrashType(unsigned char *);

unsigned char* CrashDetectionAlgorithm_GetCrashSeverity(unsigned char *);

void CrashDetectionAlgorithm_MainFunction();

int returnSTATUS();

void setSTATUS();

extern int ISCRASH;

extern unsigned char* crash_type;