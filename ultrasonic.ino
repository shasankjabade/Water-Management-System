 #define trig 9
 #define echo 8
 #define led 6
 float duration,distance;
 void setup() 
 {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

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

waterlevel = duration/58;     //conerting the time in distance(centimeters)

analogWrite(led,waterlevel);   //led intensity based on the water level values
delay (1000 ); 
Serial.print("Water level is: ");
Serial. print(distance);
Serial.println("  Centi-meters");

}
