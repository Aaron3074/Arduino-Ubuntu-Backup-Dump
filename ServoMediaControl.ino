//#include <Servo.h>
//
//Servo servo;
//int servoPin = 9;
//int angle = 85; // Default starting angle
//
//void setup() {
//  servo.attach(servoPin);
//  Serial.begin(9600);
//}
//
//void loop() {
//  if (Serial.available()) {
//    int data = Serial.parseInt(); // Read the integer data from the Serial monitor
//
//    if (data >= 0 && data <= 180) {
//      angle = data; // Update the angle if the received data is within the valid range
//      servo.write(angle); // Control the servo motor
//      delay(15); // Delay for smoother movement
//    }
//  }
//}

//#include <Servo.h>
//
//Servo servo;
//int servoPin = 9;
//int angle = 120; // Starting angle
//int repetitions = 10; // Number of repetitions
//
//void setup() {
//  servo.attach(servoPin);
//  servo.write(angle); // Set initial position
//  delay(1000); // Delay before starting the movement
//}
//
//void loop() {
//  for (int i = 0; i < repetitions; i++) {
//    // Go from 120 to 0 degrees
//    for (int currentAngle = 120; currentAngle >= 0; currentAngle--) {
//      servo.write(currentAngle);
//      delay(15); // Delay for smoother movement
//    }
//
//    // Pause at 0 degrees
//    delay(1000);
//
//    // Go from 0 to 120 degrees
//    for (int currentAngle = 0; currentAngle <= 120; currentAngle++) {
//      servo.write(currentAngle);
//      delay(15); // Delay for smoother movement
//    }
//
//    // Pause at 120 degrees
//    delay(1000);
//  }
//
//  // End of repetitions
//  while (true) {
//    // Do nothing
//  }
//}

//#include <Servo.h> 
//
//Servo myServo;  // create servo object to control a servo
//
//void setup() {
//  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
//}
//
//void loop() {
//  for(int i=0; i<10; i++){
//    for(int pos = 120; pos >= 0; pos-=5){ // goes from 120 degrees to 0 degrees 
//      myServo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15-i);                       // waits 15ms for the servo to reach the position
//    }
//    for(int pos = 0; pos <= 120; pos+=5){ // goes from 0 degrees to 120 degrees
//      myServo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15-i);                       // waits 15ms for the servo to reach the position  
//    }
//  }
//}

//#include <Servo.h> 
//
//Servo servo;
//int servoPin = 9;
//int defaultAngle = 85; 
//int angle = defaultAngle; 
//
//void setup() {
//  servo.attach(servoPin);
//  Serial.begin(9600);
//}
//
//void loop() {
//  if (Serial.available()) {
//    int input = Serial.parseInt();
//
//    if (input >= 0 && input <= 180) {
//      angle = input; 
//      servo.write(angle);
//      delay(500); // Pause at input angle
//
//      angle = defaultAngle; // Return to default angle
//      servo.write(angle);
//      delay(500); 
//    }
//  }
//}

#include <Servo.h>

// Define the servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// Pin assignments
int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

// Servo angles
int angle = 0;

// Delay between angle changes
int delayTime = 3000;

void setup() {
  // Attach the servos to their respective pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
}

void loop() {
//  servo1.write(angle);
//  servo2.write(angle);
//  servo3.write(angle);
  
//  Rotate servo1 from 0 to 150 degrees
  for (angle = 0; angle <= 150; angle++) {
    servo1.write(angle);
    delay(delayTime);
  }

  // Rotate servo1 from 150 to 0 degrees
  for (angle = 150; angle >= 0; angle--) {
    servo1.write(angle);
    delay(delayTime);
  }

  // Rotate servo2 from 0 to 150 degrees
  for (angle = 0; angle <= 100; angle++) {
    servo2.write(angle);
    delay(delayTime);
  }

  // Rotate servo2 from 150 to 0 degrees
  for (angle = 100; angle >= 0; angle--) {
    servo2.write(angle);
    delay(delayTime);
  }

  // Rotate servo3 from 0 to 150 degrees
    for (angle = 0; angle <= 50 ; angle++) {
    servo3.write(angle);
    delay(delayTime);
  }

  // Rotate servo3 from 150 to 0 degrees
    for (angle = 50; angle >= 0; angle--) {
    servo3.write(angle);
    delay(delayTime);
  }
}
