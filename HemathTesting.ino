/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

//#include <Servo.h>
//
//Servo myservo1; 
//Servo myservo2;
//Servo myservo3;
//
//
//int pos = 0;   
//
//void setup() {
//  myservo1.attach(9);
//  myservo2.attach(10); 
//  myservo3.attach(11);  
//}
//
//void loop() {
//  for (pos = 0; pos <= 90; pos += 1) { 
//    myservo1.write(pos);              
//    delay(15);
//    myservo2.write(pos);              
//    delay(15); 
//    myservo3.write(pos);              
//    delay(15);                        
//  }
//  for (pos = 90; pos >= 0; pos -= 1) { 
//    myservo1.write(pos);              
//    delay(15); 
//    myservo2.write(pos);              
//    delay(15); 
//    myservo3.write(pos);              
//    delay(15);                      
//  }
//  myservo1.write(0);
//  myservo2.write(0);
//  myservo3.write(0);
//}

#include <Servo.h>

Servo myservo1;
Servo myservo2;  
Servo myservo3;

int pos = 0;

void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
}

void loop() {

  // Move to 90 degrees
  //while(pos <= 90) {
    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);

//    pos++;
//    delay(30);
//  }

  // Hold at 90 degrees  
//  while(true) {
//    myservo1.write(90);
//    myservo2.write(90); 
//    myservo3.write(90);
//  }

}
