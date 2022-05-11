#include "MPU6500Driver.h"
#include <stdio.h>

MPU6050 mpu(Wire);

float accX, accY, accZ;
float gyrX, gyrY, gyrZ;
float angleX, angleY, angleZ;
float accangleX, accangleY;

void MPU6500Driver_Init()
{
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
                       // status 0 passed

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(true,true); // gyro and accelero
  Serial.println("Done!\n");
}

boolean MPU6500Driver_GetAccelerationData(float* accX, float* accY, float* accZ)
{
  mpu.update();
  *accX = mpu.getAccX();  //-back    +front
  *accY = mpu.getAccY();  //-right   +left
  *accZ = mpu.getAccZ();  //-down    +up
  return true;    
}

boolean MPU6500Driver_GetGyroData(float* gyrX, float* gyrY, float* gyrZ)
{
  mpu.update();
  *gyrX = mpu.getGyroX();
  *gyrY = mpu.getGyroY();
  *gyrZ = mpu.getGyroZ();
  return true;
}

boolean MPU6500Driver_GetAngleData(float* angleX, float* angleY, float* angleZ)
{
  mpu.update();
  *angleX=mpu.getAngleX();
  *angleY=mpu.getAngleY();
  *angleZ=mpu.getAngleZ();
  return true;
}

boolean MPU6500Driver_GetAngularAccelerationData(float* accangleX, float* accangleY)
{
  mpu.update();
  *accangleX=mpu.getAccAngleX();
  *accangleY=mpu.getAccAngleY();
  return true;
}

float return_accx()
{
  return accX;
}

float return_accy()
{
  return accY;
}

void MPU6500Driver_MainFunction()
{
  /*float accX, accY, accZ;
float gyrX, gyrY, gyrZ;
float angleX, angleY, angleZ;
float accangleX, accangleY;*/
  MPU6500Driver_GetAccelerationData(&accX, &accY, &accZ);
  MPU6500Driver_GetGyroData(&gyrX, &gyrY, &gyrZ);
  MPU6500Driver_GetAngleData(&angleX, &angleY, &angleZ);
  MPU6500Driver_GetAngularAccelerationData(&accangleX, &accangleY);


  Serial.print("ACC: ");
  Serial.print(accX);
  Serial.print(",");
  Serial.print(accY);
  Serial.print(",");
  Serial.println(accZ);
  Serial.print("GYRO: ");
  Serial.print(gyrX);
  Serial.print(",");
  Serial.print(gyrY);
  Serial.print(",");
  Serial.println(gyrZ);
  Serial.print("ANGLE: ");
  Serial.print(angleX);
  Serial.print(",");
  Serial.print(angleY);
  Serial.print(",");
  Serial.println(angleZ);
  Serial.print("ANGULAR ACC: ");
  Serial.print(accangleX);
  Serial.print(",");
  Serial.println(accangleY);
  Serial.println();
 
}

