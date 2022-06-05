#include <MPU6050_light.h>

extern unsigned long timer;

void MPU6500Driver_Init();

void MPU6500Driver_MainFunction();

boolean MPU6500Driver_GetAccelerationData(float*, float*, float*);

boolean MPU6500Driver_GetGyroData(float*, float*, float*);

boolean MPU6500Driver_GetSensorTemperature(float*);

boolean MPU6500Driver_GetAngleData(float*, float*, float*);

boolean MPU6500Driver_IsProveoutComplete();

boolean MPU6500Driver_GetAngularAccelerationData(float*, float*);

void MPUDriver_update();

extern MPU6050 mpu;











