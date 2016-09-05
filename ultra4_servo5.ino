 //code run in ARDUINO DUE 
 
 #define trig1 22
 #define echo1 8
 #define trig2 2
 #define echo2 3
 #define trig3 4
 #define echo3 5
 #define trig4 6
 #define echo4 7

 
 
 #include <Servo.h> 
 
Servo servo1;
Servo servo2;// create servo object to control a servo 
Servo servo3;                // twelve servo objects can be created on most boards
Servo servo4;
Servo servo5;                

 float duration1,distance1,duration2,distance2,duration3,distance3,duration4,distance4;
 void setup() 
 {
 Serial.begin(9600);

 pinMode(trig1,OUTPUT);
 pinMode(echo1,INPUT);

 pinMode(trig2,OUTPUT);
 pinMode(echo2,INPUT);
 
 pinMode(trig3,OUTPUT);
 pinMode(echo3,INPUT);

 pinMode(trig4,OUTPUT);
 pinMode(echo4,INPUT);
 
 pinMode(led,OUTPUT);
 
 
 servo1.attach(9);  // attaches the servo1 on pin 9 to the servo object 
 servo2.attach(10); // attaches the servo2 on pin 10 to the servo object
 servo3.attach(11); // attaches the servo3 on pin 11 to the servo object
 servo4.attach(12); // attaches the servo4 on pin 12 to the servo object
  servo5.attach(13); // attaches the servo5 on pin 13 to the servo object
 


}

void loop() 
{

  digitalWrite(trig1,LOW);
  delayMicroseconds(2000);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

duration1 = pulseIn(echo1,HIGH);
                   
distance1 = duration1/58;
 
 digitalWrite(trig2,LOW);
  delayMicroseconds(2000);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);

duration2 = pulseIn(echo2,HIGH);

distance2 = duration2/58;

  digitalWrite(trig3,LOW);
  delayMicroseconds(2000);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3,LOW);

duration3 = pulseIn(echo3,HIGH);

distance3 = duration3/58;
 
  digitalWrite(trig4,LOW);
  delayMicroseconds(2000);
  digitalWrite(trig4,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4,LOW);

duration4 = pulseIn(echo4,HIGH);

distance4 = duration4/58;

  
  
  
  Serial.println(distance1);
  Serial.println("sensor1");
  
  delay(500);
  
  Serial.println(distance2);
  Serial.println("sensor2");

  delay(500);
  
  Serial.println(distance3);
  Serial.println("sensor3");

  delay(500);
  
  Serial.println(distance4);
  Serial.println("sensor4");

  delay(500);
  
   if(distance1<20)
  {
  servo1.write(0);
  }
  else
 
  {
     servo1.write(100);
 
  }
  
   if(distance2<20)
  {
  servo2.write(0);
  }
  else
 
  {
     servo2.write(100);
 
  }
  
  if(distance3<20)
  {
  servo3.write(0);
  }
  else
 
  {
     servo3.write(100);
 
  }
  
   if(distance4<20)
  {
  servo4.write(0);
  }
  else
 
  {
     servo4.write(100);
 
  }
  
  if((distance1<20) && (distance2<20)&&(distance3<20) && (distance4<20) )
  {
  servo5.write(100);
  Serial.println("The main gate is closed ");
  }
  else
 
  {
     
  servo4.write(0);
  Serial.println("The main gate is opened  ");
  }
}

