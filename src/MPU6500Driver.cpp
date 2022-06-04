#include "MPU6500Driver.h"

MPU6050 mpu(Wire);

unsigned long timer = 0;  //still needs to be defined 
                          //definition of extern declarations in header

float accX, accY, accZ;       //acceleration data
float gyroX, gyroY, gyroZ;    //gyro_data
float temp;                   //temperature sensor
float angleX, angleY, angleZ; //angle_data
float acc_angleX, acc_angleY; //angular_acc_data

void MPU6500Driver_Init(){

  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  mpu.calcOffsets(true,true); // gyro and accelero
  while(status!=0){ } // stop everything if could not connect to MPU6050
                      // status 0 passed

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  Serial.println("Done!\n");
}


boolean MPU6500Driver_GetAccelerationData(float* accX_p, float* accY_p, float* accZ_p){

  *accX_p = accX;
  *accY_p = accY;
  *accZ_p = accZ;

  return true;
}

boolean MPU6500Driver_GetGyroData(float* gyroX_p, float* gyroY_p, float* gyroZ_p){

  *gyroX_p = gyroX;
  *gyroY_p = gyroY;
  *gyroZ_p = gyroZ;

  return true;
}

boolean MPU6500Driver_GetSensorTemperature(float* temp_p){

  *temp_p = temp;

  return true;
}

boolean MPU6500Driver_GetAngleData(float* angleX_p, float* angleY_p, float* angleZ_p){
    
  *angleX_p = angleX;
  *angleY_p = angleY;
  *angleZ_p = angleZ;

  return true;
}

boolean MPU6500Driver_GetAngularAccelerationData(float* acc_angleX_p, float* acc_angleY_p){

  *acc_angleX_p = acc_angleX;
  *acc_angleY_p = acc_angleY;

  return true;
}

void MPU6500Driver_MainFunction(){

  mpu.update();

  accX = mpu.getAccX(); //setters
  accY = mpu.getAccY();
  accZ = mpu.getAccZ();

  gyroX = mpu.getGyroX();
  gyroY = mpu.getGyroY();
  gyroZ = mpu.getGyroZ();

  temp = mpu.getTemp();

  acc_angleX = mpu.getAccAngleX();
  acc_angleY = mpu.getAccAngleY();

  angleX = mpu.getAngleX();
  angleY = mpu.getAngleY();
  angleZ = mpu.getAngleZ();



  // if(millis() - timer > 10000){ // print data every second
    
  //   Serial.print(F("ACCELERO  X: "));Serial.print(accX); //acceleration data
  //   Serial.print("\tY: ");Serial.print(accY);
  //   Serial.print("\tZ: ");Serial.println(accZ);
  
  //   Serial.print(F("GYRO      X: "));Serial.print(gyroX); //gyro_data
  //   Serial.print("\tY: ");Serial.print(gyroY);
  //   Serial.print("\tZ: ");Serial.println(gyroZ);
  
  //   Serial.print(F("TEMPERATURE: "));Serial.println(temp); //temperature sensor

  //   Serial.print(F("ANGLE     X: "));Serial.print(angleX); //angle_data
  //   Serial.print("\tY: ");Serial.print(angleY);
  //   Serial.print("\tZ: ");Serial.println(angleZ);

  //   Serial.print(F("ACC ANGLE X: "));Serial.print(acc_angleX); //angular_acc_data
  //   Serial.print("\tY: ");Serial.println(acc_angleY);
    
  //   Serial.println(F("=====================================================\n"));
  //   timer = millis();
  // }
  
  
  //export putty plot:

  // Serial.print(accX);
  // Serial.print(",");
  // Serial.print(accY);
  // Serial.print(",");
  // Serial.println(accZ);

  // Serial.print(gyroX);
  // Serial.print(",");
  // Serial.print(gyroY);
  // Serial.print(",");
  // Serial.println(gyroZ);
  
  // Serial.println(temp);
  
  // Serial.print(angleX);
  // Serial.print(",");
  // Serial.print(angleY);
  // Serial.print(",");
  // Serial.println(angleZ);

  // Serial.print(acc_angleX);
  // Serial.print(",");
  // Serial.println(acc_angleY);
  
}
