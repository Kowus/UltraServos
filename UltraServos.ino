/*
 * Ultrasonic Servos Interaction
 * 
 
 *    By Barnabas Nomo <http://www.github.com/kowus>
 *    This sample code is in the public domain
 *    
 *    powered by <http://www.elite-education.org>
*/



#include <Ultrasonic.h>
#include <Servo.h>

Servo myServo;   // Create instance for sservo

Ultrasonic ultraleft(9,8, 3000);   // (Trig PIN,Echo PIN, TimeOut)
Ultrasonic ultraright(7,6, 3000);  // (Trig PIN,Echo PIN, TimeOUt)

// The TimeOut is the range you want to give the ultrasonic sensor

// 3000 = 51cm
// 30000 = 517cm
// 300000 = 5172cm

// KEEP THAT IN MIND ANYTIME YOU WORK WITH THIS LIBRARY




int pos = 90;

int buzzer = 13; //Noise Maker... To attract attention to myself B-)


//unsigned long previousMillis;    // Want to combat noise.. but too lazy to continue... 

void setup() {
  Serial.begin(9600);              // Ready for Serial Communication with baud rate of 9600
  pinMode(buzzer, OUTPUT);         // Buzzer attached to pin 13 set as output
  myServo.attach(11);              // Servo attached to pin 11

  // Need To Know Classified
}

void loop()
{
  //unsigned long currentMillis = millis();   // ignore  unless you want to combat noise.. 
                                              // then i can help
  int left = ultraleft.Ranging(CM);
  int right = ultraright.Ranging(CM);

  Serial.print("Left: ");
  Serial.print(ultraleft.Ranging(CM)); // CM or INC
  Serial.print(" cm     " );

  // Print The value of the left sensor to serial
  
  Serial.print("Right: ");
  Serial.print(ultraright.Ranging(CM)); // CM or INC
  Serial.println(" cm" );

  // Print The value of the right sensor to serial
  
  
  if(right <= 10)
  {
      pos = 0;
      myServo.write(pos);              // Set servo to 0 degrees
      digitalWrite(buzzer, HIGH);      // Make Noise... attention seeking
    
  }

  else if (left <= 10)
  {
      pos = 180;
      myServo.write(pos);              // Set servo to 180 degrees
      digitalWrite(buzzer, HIGH);      // Make Noise... attention seeking
     
  }
  else
  {
    pos = 90;                         // Center servo
    myServo.write(pos);
    digitalWrite(buzzer, LOW);        // Quiet...
  }
  
}
