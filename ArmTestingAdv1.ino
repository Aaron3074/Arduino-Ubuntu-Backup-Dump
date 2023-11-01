//All 3 motors together 
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

int angle1 = 0;
int angle2 = 90;
int angle3 = 0;
int i=0;

void movetopose(int x, int y) {
  int increment = (y > x) ? 1 : -1;
  for (i = x; i != y; i += increment) {
    x = i;
//   if (pin==9){
//      servo1.write(x);
//      Serial.println(x);
//      } 
//     if (pin==10){
//      servo2.write(x);
//      Serial.println(x);
//      }
//      if (pin==11){
//        servo3.write(x);
//        Serial.println(x);
//        }
//    delay(50);
    Serial.println(i);
    return i;
  }
//  for (int j = y; j != x; j -= increment){
//    y = j;
//    servo1.write(y);
//    Serial.println(y);
//    delay(100);
//    }
}

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  Serial.begin(9600);
}

void loop() {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);

  Serial.println("Testing motor 1");
  delay(1000);
  movetopose(angle1, 100);
  servo1.write(i);
  delay(1000);

  Serial.println("Testing motor 2");
  delay(1000);
  movetopose(angle2, 120);
  servo2.write(i);
  delay(1000);
  movetopose(angle2, 50);
  servo2.write(i);
  delay(1000);

  Serial.println("Testing motor 3");
  delay(1000);
  movetopose(angle3, 110 );
  servo3.write(i);
  delay(1000);
}


//
//#include <Servo.h>
//
//Servo servo1;  
//Servo servo2;
//Servo servo3;
//
//int servoPin1 = 9;
//int servoPin2 = 10; 
//int servoPin3 = 11;
//
//int angle1 = 0;
//int angle2 = 90;
//int angle3 = 0;
//
//void sweepServo(int& angle, int start, int end) {
//  int increment = (end > start) ? 1 : -1;
//  for(int i=start; i!=end; i+=increment) {
//    angle = i;
//    delay(50);
//  }
//}
//
//void setup() {
//  servo1.attach(servoPin1);
//  servo2.attach(servoPin2);
//  servo3.attach(servoPin3);
//  Serial.begin(9600);
//}
//
//void loop() {
//  servo1.write(angle1); 
//  servo2.write(angle2);
//  servo3.write(angle3);  
//  sweepServo(angle1, 0, 180);
//  delay(500);
//  sweepServo(angle2, 0, 180);
//  delay(500);
//  sweepServo(angle3, 0, 180);
//  delay(500);
//}
