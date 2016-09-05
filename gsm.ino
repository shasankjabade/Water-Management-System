#include <SoftwareSerial.h>
SoftwareSerial gsm(7,8);  //using port 7 as Rx and port 8 as Tx
void setup() 
{
Serial.begin(9600);  //defining the baud rate of as per requirement
delay(100);
gsm.begin(9600);
}

void loop()
{

  
 gsm.println("ATD+91**********;");        //code_start for calling using gsm -enter the number to which you need to call
  delay(100);
  gsm.println();
  Serial.println("calling...tring tring...");
  delay(15000);
  gsm.println("ATH");
  Serial.println("calling complete");
  delay(1000);                          //code_end for gsm calling  

  
gsm.print("AT+CMGF=1\r\n");                 //code_start for texting using gsm
delay(1000);
gsm.print("AT+CMGS=\"");
gsm.print("**********");                  //enter the number to which you need to send message
gsm.print("\"\r\n");
delay(1000);
gsm.print("Kindly note that this is a test message sent to you through ARDUINO SOFTWARE interfacing with GSM by Simpi:)");
Serial.println("texting to the number "); 
gsm.print(0X1A);
while(1);                                 //code_end for calling using gsm
Serial.println("Your messsage has been delivered!");// put your main code here, to run repeatedly:   
}
