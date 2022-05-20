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

boolean MPU6500Driver_GetAccelerationData(float* accX_p, float* accY_p, float* accZ_p)
{
  *accX_p=accX;
  *accY_p=accY;
  *accZ_p=accZ;
  return true;    
}

boolean MPU6500Driver_GetGyroData(float* gyrX_p, float* gyrY_p, float* gyrZ_p)
{
  *gyrX_p=gyrX;
  *gyrY_p=gyrY;
  *gyrZ_p=gyrZ;
  return true;
}

boolean MPU6500Driver_GetAngleData(float* angleX_p, float* angleY_p, float* angleZ_p)
{
  *angleX_p=angleX;
  *angleY_p=angleY;
  *angleZ_p=angleZ;
  return true;
}

boolean MPU6500Driver_GetAngularAccelerationData(float* accangleX_p, float* accangleY_p)
{
  *accangleX_p=accangleX;
  *accangleY_p=accangleY;
  return true;
}

void Just_Update()
{
   mpu.update();
}

void MPU6500Driver_MainFunction()
{
  mpu.update();
  accX = mpu.getAccX();  //-back    +front
  accY = mpu.getAccY();  //-right   +left
  accZ = mpu.getAccZ();  //-down    +up

  gyrX = mpu.getGyroX();
  gyrY = mpu.getGyroY();
  gyrZ = mpu.getGyroZ();

  angleX=mpu.getAngleX();
  angleY=mpu.getAngleY();
  angleZ=mpu.getAngleZ();

  accangleX=mpu.getAccAngleX();
  accangleY=mpu.getAccAngleY();

/*
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
  */
}

