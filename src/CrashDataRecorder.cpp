#include "CrashDataRecorder.h"
#include "MPU6500Driver.h"
#include "CrashDetectionAlgorithm.h"
#include "EEPROM.h"
#include "MPU6500Driver.h"

float accx_a[4] = {0,0,0,0};
float accy_a[4] = {0,0,0,0};
float accz_a[4] = {0,0,0,0};

float accx_d, accy_d, accz_d;

unsigned long int timer2 = 0;

void CrashDataRecorder_MainFunction(){

    float valoare;
    int i;
    int cnt = 1, cnt_write = 0;
    if(returnSTATUS() == false) //no crash
    {

    if(millis() - timer > 250){
        

        MPU6500Driver_GetAccelerationData(&accx_d, &accy_d, &accz_d);

        memcpy(accx_a, accx_a + 1, 3*sizeof(float));
        memcpy(accy_a, accy_a + 1, 3*sizeof(float));
        memcpy(accz_a, accz_a + 1, 3*sizeof(float));

        accx_a[3] = accx_d;
        accy_a[3] = accy_d;
        accz_a[3] = accz_d;

        timer = millis();
        
    }

    }
    else    //is crash
    {   
        Serial.println("a avut loc accident");
        Serial.println("before----------------------\n");

        for(int i=0;i<4;i++)      //values before
        {
            Serial.println(accx_a[i]);
            EEPROM.put(cnt,accx_a[i]);
            cnt+=sizeof(float);

            Serial.println(accy_a[i]);
            EEPROM.put(cnt,accy_a[i]);
            cnt+=sizeof(float);

            Serial.println(accz_a[i]);
            EEPROM.put(cnt,accz_a[i]);
            cnt+=sizeof(float);

            Serial.println();
        }
            
            Serial.println("t0----------------------\n");

            //values at crash (t0)
            MPU6500Driver_GetAccelerationData(&accx_d, &accy_d, &accz_d);

            Serial.println(accx_d);
            EEPROM.put(cnt,accx_d);
            cnt+=sizeof(float);
            
            Serial.println(accy_d);
            EEPROM.put(cnt,accy_d);
            cnt+=sizeof(float);

            Serial.println(accz_d);
            EEPROM.put(cnt,accz_d);
            cnt+=sizeof(float);
            Serial.println();

        Serial.println("after----------------------\n");
        //values after t0 = t0

        //setSTATUS();

        // while(cnt_write<4)
        // {
        
        // float accx_df, accy_df, accz_df;

        // while(millis() - timer < 1000){
            
        //     MPUDriver_update();
        //     MPU6500Driver_GetAccelerationData(&accx_df, &accy_df, &accz_df);
        // }

        //     Serial.println(accx_df);
        //     EEPROM.put(cnt,accx_df);
        //     cnt+=sizeof(float);

        //     Serial.println(accy_df);
        //     EEPROM.put(cnt,accy_df);
        //     cnt+=sizeof(float);

        //     Serial.println(accz_df);    

        //     EEPROM.put(cnt,accz_df);
        //     cnt+=sizeof(float);
        //     Serial.println();

        //     cnt_write++;
        //     timer = millis();
        
        // }

        for(cnt_write = 0; cnt_write < 4; cnt_write++){

            while(millis() - timer < 1000);
                
            float accx_df, accy_df, accz_df;

            MPU6500Driver_GetAccelerationData(&accx_df, &accy_df, &accz_df);

            mpu.update();

            Serial.println(mpu.getAccX());
            Serial.println(mpu.getAccY());
            Serial.println(mpu.getAccZ());

            EEPROM.put(cnt,mpu.getAccX());
            cnt+=sizeof(float);

            EEPROM.put(cnt,mpu.getAccY());
            cnt+=sizeof(float);

            EEPROM.put(cnt,mpu.getAccZ());
            cnt+=sizeof(float);



            timer = millis();
            
        }

        Serial.println();
        Serial.println();
        Serial.println();
        Serial.println();
        Serial.println();

        Serial.println("get_EEPROM----------------------\n");

        i=1;
        cnt_write=0;
        Serial.println(i);
        while(i<=cnt)
        {
            cnt_write++;
            EEPROM.get(i,valoare);
            i+=sizeof(float);
            Serial.println(valoare);
            if(cnt_write==3)
            {
                cnt_write=0;
                Serial.println();
            }
        }

        Serial.println("termin de recordat datele");
    }
    
}