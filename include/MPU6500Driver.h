#include <MPU6050_light.h>

extern unsigned long timer;
extern float accX, accY, accZ;
extern float gyrX, gyrY, gyrZ;
extern float angleX, angleY, angleZ;
extern float accangleX, accangleY;

void MPU6500Driver_Init();

void MPU6500Driver_MainFunction();

boolean MPU6500Driver_GetAccelerationData(float*, float*, float*);

boolean MPU6500Driver_GetGyroData(float*, float*, float*);

boolean MPU6500Driver_GetSensorTemperature(float*);

boolean MPU6500Driver_GetAngleData(float*, float*, float*);

boolean MPU6500Driver_IsProveoutComplete();

boolean MPU6500Driver_GetAngularAccelerationData(float*, float*);






