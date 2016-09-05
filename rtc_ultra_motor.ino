// Date and time functions using just software, based on millis() & timer

#include <Wire.h>
#include "RTClib.h"
//include <LiquidCrystal.h>
 #include <Servo.h>
 #define trig 9
 #define echo 8
 
 int duration,distance;

 Servo servo1;      // create servo object to control a servo     
  

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int hh,mm,ss;

RTC_Millis rtc;
DateTime now = rtc.now();

void setup () {
    
    Serial.begin(9600);
    //pinMode(led, OUTPUT);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
     
    servo1.attach(10); 
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    
    
}

void loop ()
{
  
  digitalWrite(trig,LOW);        //set the trig pin to low
  delayMicroseconds(2000);       //pause to let signal settle
  digitalWrite(trig,HIGH);       //set the trig pin to high
  delayMicroseconds(10);        //pause signal at high state
  digitalWrite(trig,LOW);         //set the trig pin to low
  
  
   mm=int(now.minute());  
  

  duration = pulseIn(echo,HIGH); //measure time at echo pin in microseconds
//duration =duration/1000000;     //converting time in seconds

  distance = duration/58;     //conerting the time in distance(centimeters)
  DateTime now = rtc.now();
     
      Serial.println(distance);
      Serial.println(mm);
      delay(1000);
     
     
    if(now.minute()==mm+1)
    {
      if(distance>10)
      {
      Serial.println("Water level HIGH(Centi-meters): ");   //serial monitor 
      Serial. println(distance);
                               
      servo1.write(0);              // goes from 0 degrees to 100 degrees     
      delay(250); 
      }
      else
      {
        servo1.write(100);
      }
    
    }
    
       if(now.minute()==mm+2)
    {
      if(distance>20)
      {
      Serial.println("Water level HIGH(Centi-meters): ");   //serial monitor 
      Serial. println(distance);
   
                               
      servo1.write(0);              // goes from 0 degrees to 100 degrees     
      delay(250); 
      }
      else
      {
        servo1.write(100);
      }
    
    }


}
 
 

