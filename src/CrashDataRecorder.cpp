#include "CrashDataRecorder.h"
#include "MPU6500Driver.h"

float accx_a[4] = {0,0,0,0};
float accy_a[4] = {0,0,0,0};
float accz_a[4] = {0,0,0,0};

float accx_d, accy_d, accz_d;

unsigned long int timer = 0;

void CrashDataRecorder_MainFunction(){

    float valoare;
    int i;
    int cnt=1, cnt_write=0;
    if(returnSTATUS()==false)
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
    else
    {
        for(int i=0;i<4;i++)
        {
            Serial.println(accx_a[i]);
            EEPROM.put(cnt,accx_a[i]);
            cnt+=sizeof(float);

            Serial.println(accy_a[i]);
            EEPROM.put(cnt,accy_a[i]);
            cnt+=sizeof(float);

            Serial.println(accz_a[i]);
            EEPROM.put(cnt,accy_a[i]);
            cnt+=sizeof(float);

            Serial.println();
        }
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

        while(cnt_write<4)
        {
        if(millis() - timer > 250)
        {
            Just_Update();
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

            cnt_write++;
            timer = millis();
        }
        }
        Serial.println();
        Serial.println();
        Serial.println();
        Serial.println();
        Serial.println();

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
    }
}