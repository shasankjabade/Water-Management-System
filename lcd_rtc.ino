// Date and time functions using just software, based on millis() & timer

#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

RTC_Millis rtc;

void setup () {
    lcd.begin(16,2);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop () {
    DateTime now = rtc.now();
//lcd.setCursor(0, 0);
  //  lcd.print("Digital Clock");
    lcd.setCursor(0, 0);
    lcd.print(now.day(), DEC);
    lcd.print('/');  
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.year(), DEC);
    lcd.print(' ');
    lcd.setCursor(0,1);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    delay(1000);
     lcd.setCursor(11,0);
     int dayofweek = now.dayOfWeek();
     
   switch(dayofweek){
     case 1:
     lcd.print("Mon");
     break;
     case 2:
     lcd.print("Tue");
     break;
     case 3:
     lcd.print("Wed");
     break;
     case 4:
     lcd.print("Thur");
     break;
     case 5:
     lcd.print("Fri");
     break;
     case 6:
     lcd.print("Sat");
     break;
     case 0:
     lcd.print("Sun");
     break;
    delay(1000);

}
 
 
}
