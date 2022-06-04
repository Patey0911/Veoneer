#include<GSMDriver.h>

//#define RX 25
//#define TX 27
/*
GSMSim gsm(0,1);

void GsmDriver_Init()
{
      Serial.begin(9600);

  Serial.println("GSMSim Library - SMS Example");
  Serial.println("");
  delay(1000);

  gsm.start(); // baud default 9600
  //gsm.start(BAUD);
}

bool GsmDriver_TriggerSmsTransmission();

void GsmDriver_SetSmsData()
{
  /*
    Serial.println("Changing to text mode.");
  gsm.smsTextMode(true); // TEXT or PDU mode. TEXT is readable :)

  char* number = "+40725661830";
  char* message = "Hi my friend. How are you?"; // message lenght must be <= 160. Only english characters.

  Serial.println("Sending Message --->");
  Serial.println(gsm.smsSend(number, message)); // if success it returns true (1) else false (0)
  delay(2000);
  */
 /*

  Serial.println("Listing unread message(s).");
  Serial.println(gsm.smsListUnread()); // if not unread messages have it returns "NO_SMS"

  Serial.println("Read SMS on index no = 1");
  Serial.println(gsm.smsRead(1)); // if no message in that index, it returns IXDEX_NO_ERROR
  
}

void GsmDriver_MainFunction();

bool GsmDriver_IsProveoutComplete();
*/