#include "CrashReactionManager.h"
#include "CrashDetectionAlgorithm.h"
#include "MPU6500Driver.h"
#include <Arduino.h>


void CrashReactionManager_Init(){

    // crash_type_react = NULL;
    // crash_severity_react = NULL;

}

void CrashReactionManager_MainFunction(){


    unsigned char* crash_type_react = CrashDetectionAlgorithm_GetCrashType(crash_type_react);
    unsigned char* crash_severity_react = CrashDetectionAlgorithm_GetCrashSeverity(crash_severity_react);

    // if(returnSTATUS() == 1){

    //     Serial.print("crash type react: ");
    //     Serial.println((char*)crash_type_react);

    //     Serial.print("crash severity react: ");
    //     Serial.println((char*)crash_severity_react);
    // }


    if(returnSTATUS() == 1 && strcmp((char*)crash_type_react, "FRONT CRASH") == 0){ 
        Serial.println("intru la led-uri");
        if(strcmp((char*)crash_severity_react, "HIGH CRASH") == 0){  //8, 7 -> 2s

            
            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 2000){
                digitalWrite(8, HIGH);
                digitalWrite(7, HIGH);
                
            }
            Serial.println("if front high");
            digitalWrite(8, LOW);
            digitalWrite(7, LOW);
            
        }else{  //8, 7 -> 1s

            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 1000){
                digitalWrite(8, HIGH);
                digitalWrite(7, HIGH);
            }

            Serial.println("if front low");
            digitalWrite(8, LOW);
            digitalWrite(7, LOW);

        }
        Serial.println("ies de la led-uri");
    }

    if(returnSTATUS() == 1 && strcmp((char*)crash_type_react, "LEFT CRASH") == 0){ 
        Serial.println("intru la led-uri");
        if(strcmp((char*)crash_severity_react, "HIGH CRASH") == 0){  //6 -> 2s

            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 2000){
                digitalWrite(6, HIGH);
                
            }
            Serial.println("if left high");
            digitalWrite(6, LOW);

        }else{  //6 -> 1s

            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 1000){
                digitalWrite(6, HIGH);
            }

            Serial.println("if left low");
            digitalWrite(6, LOW);

        }
        Serial.println("ies de la led-uri");

    }

    if(returnSTATUS() == 1 && strcmp((char*)crash_type_react, "RIGHT CRASH") == 0){ 
        Serial.println("intru la led-uri");
        if(strcmp((char*)crash_severity_react, "HIGH CRASH") == 0){  //5 -> 2s

            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 2000){
                digitalWrite(5, HIGH);
                
            }
            Serial.println("if right high");
            digitalWrite(5, LOW);
            
        }else{  //5 -> 1s

            unsigned int timer_initial = millis();
            while(millis() < timer_initial + 1000){
                digitalWrite(5, HIGH);
            }

            Serial.println("if right low");
            digitalWrite(5, LOW);

        }
        Serial.println("ies de la led-uri");
    }

}

void CrashReactionManager_GetDeploymentMask(unsigned char *){
    
    
}