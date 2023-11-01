//Test 1
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
//int angle = 0;
//
//int delayTime = 2000;
//
//void setup() {
//  servo1.attach(servoPin1);
//  servo2.attach(servoPin2);
//  servo3.attach(servoPin3);
//}
//
//void loop() {
////  servo1.write(angle);
////  servo2.write(angle);
////  servo3.write(angle);
//  
//  for (angle = 0; angle <= 150; angle++) {
//    servo1.write(angle);
//    delay(delayTime);
//  }
//  for (angle = 150; angle >= 0; angle--) {
//    servo1.write(angle);
//    delay(delayTime);
//  }
//
//  for (angle = 0; angle <= 100; angle++) {
////    servo2.write(angle);
////    delay(delayTime);
////  }
////  for (angle = 100; angle >= 0; angle--) {
////    servo2.write(angle);
////    delay(delayTime);
////  }
////  
////    for (angle = 0; angle <= 50 ; angle++) {
////    servo3.write(angle);
////    delay(delayTime);
////  }
////    for (angle = 50; angle >= 0; angle--) {
////    servo3.write(angle);
////    delay(delayTime);
//  }
//}



// Test 2

//#include <Servo.h>
//
//Servo servo;
//int servoPin = 9;
//int angle = 0; 
//void setup() {
//  servo.attach(servoPin);
//  Serial.begin(9600);
//}
//
//void loop() {
//  if (Serial.available()) {
//    int data = Serial.parseInt();
//
//    if (data >= 0 && data <= 180) {
//      angle = data; 
//      servo.write(angle); 
//      delay(1000);
//    }
//  }
//}


//Test 3 - Position and Disconnect the signal pin
#include <Servo.h>

Servo servo;
int servoPin = 9;
int angle = 0; 

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int data = Serial.parseInt();

    if (data >= 0 && data <= 90) {
      angle = data;
      servo.write(angle);
      delay(1000);
    }
  }
}

//Test 4 - Test 2 with loops 
//#include <Servo.h>
//
//Servo servo;
//int servoPin = 9;
//int angle = 0; 
//
//void setup() {
//  servo.attach(servoPin);
//  Serial.begin(9600);
//}
//
//void loop() {
//  if (Serial.available()) {
//    int data = Serial.parseInt();
//    Serial.println(data);
//    
//
//    if (data >= 0 && data <= 180) {
//      int targetAngle = data;
//
//      if (angle != targetAngle) {
//        int increment = (targetAngle > angle) ? 1 : -1;
//        for (int i = angle; i != targetAngle; i += increment) {
//          angle = i;
//          servo.write(angle);
//          delay(20);
//        }
//      }
//    }
//  }
//}

//Test 5 - new shit
//#include <Servo.h>
//
//Servo servo;
//int servoPin = 9;
//
//int currentAngle = 0;
//
//void setup(){
//
//servo.attach(servoPin);
//Serial.begin(9600);
//
//currentAngle = servo.read();
//
//}
//
//void loop(){
//
//if(Serial.available()){
//int newAngle = Serial.parseInt();
//
//if(newAngle >= 0 && newAngle <= 180){
//
//if(newAngle != currentAngle){
//
//if(newAngle > currentAngle){
//for(; currentAngle<=newAngle; currentAngle++){
//servo.write(currentAngle); 
//delay(15);
//}
//}
//else{
//for(; currentAngle>=newAngle; currentAngle--){ 
//servo.write(currentAngle);
//delay(15); 
//}
//}
//
//}
//
//currentAngle = newAngle;
//
//}
//}
//
//}
