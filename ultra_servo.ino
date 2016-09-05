 #include <Servo.h>
 #define trig 9
 #define echo 8
 #define led 6
 int duration,distance;

 Servo servo1;      // create servo object to control a servo     
 int pos = 0;    // variable to store the servo position 
 
 void setup() 
 {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

servo1.attach(10);      // attaches the servo on pin 9 to the servo object 

}

void loop() 
{

  digitalWrite(trig,LOW);        //set the trig pin to low
  delayMicroseconds(2000);       //pause to let signal settle
  digitalWrite(trig,HIGH);       //set the trig pin to high
  delayMicroseconds(10);        //pause signal at high state
digitalWrite(trig,LOW);         //set the trig pin to low


duration = pulseIn(echo,HIGH); //measure time at echo pin in microseconds
duration =duration/1000000;     //converting time in seconds

distance = duration/58;     //conerting the time in distance(centimeters)

analogWrite(led,distance);   //led intensity based on the water level values
delay (1000 );        
if(distance >20)
{

Serial.println("Water level HIGH(Centi-meters): ");   //serial monitor 
Serial. println(distance);
                               
    servo1.write(100);              // goes from 0 degrees to 100 degrees     
    delay(15); 
     
  }

 while( distance<=20)
  {
          
   Serial.println("Water level LOW(Centi-meters): ");   //serial monitor 
   Serial. println(distance);
    servo1.write(0);              // goes from 100 degrees to 0 degrees     
    delay(15); 
     
}
}

