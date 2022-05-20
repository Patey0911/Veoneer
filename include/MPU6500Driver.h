#include <MPU6050_light.h>

void MPU6500Driver_Init();

void MPU6500Driver_MainFunction();

boolean MPU6500Driver_GetAccelerationData(float*, float*, float*);

boolean MPU6500Driver_GetGyroData(float*, float*, float*);

boolean MPU6500Driver_GetSensorTemperature(float*);

boolean MPU6500Driver_GetAngleData(float*, float*, float*);

boolean MPU6500Driver_IsProveoutComplete();

boolean MPU6500Driver_GetAngularAccelerationData(float*, float*);

float return_accx();

float return_accy();

void Just_Update();

