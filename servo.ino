

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{
 
   myservo.write(0);              // tell servo to go to position in variable position = 0
    delay(1000);                       // waits 1 second for the servo to reach the next position

    myservo.write(100);              // tell servo to go to position in variable 'position =100'
    delay(1000);                       // waits 1 second for the servo to reach the next position
  }
}

