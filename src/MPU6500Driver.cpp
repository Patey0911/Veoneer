#include "MPU6500Driver.h"
#include <stdio.h>

MPU6050 mpu(Wire);

unsigned long timer = 0;


void MPU6500Driver_Init(){

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

  *accX = mpu.getAccX();  //update in loop
  *accY = mpu.getAccY();
  *accZ = mpu.getAccZ();
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

void MPU6500Driver_MainFunction(){


  float accX, accY, accZ;
  float gyrX, gyrY, gyrZ;

  MPU6500Driver_GetAccelerationData(&accX, &accY, &accZ);
  MPU6500Driver_GetGyroData(&gyrX, &gyrY, &gyrZ);
  
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
}
