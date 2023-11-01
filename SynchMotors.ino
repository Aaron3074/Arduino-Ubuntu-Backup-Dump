#include <Servo.h>

Servo base1;
Servo shoulder1;
Servo elbow1;

int base_pin = 9;
int shoulder_pin = 10;
int elbow_pin = 11;

int base_angle = 0;
int shoulder_angle = 90;
int elbow_angle = 0;

int delay1 = 50;

void setup(){
  base1.attach(base_pin);
  shoulder1.attach(shoulder_pin);
  elbow1.attach(elbow_pin);

  Serial.begin(9600);

  base1.write(base_angle);
  shoulder1.write(shoulder_angle);
  elbow1.write(elbow_angle);
  }

void loop(){
  for (int i = base_angle; i <= 130; i++){
    base1.write(i);
    delay(delay1);
    }
   for (int j = shoulder_angle; j <= 110; j++){
      shoulder1.write(j);
      delay(delay1);
    }
    for(int k = elbow_angle; k <= 120; k++){
      elbow1.write(k);
      delay(delay1);
      }
     for (int i2 = 130; i2 >= base_angle; i2--){
        base1.write(i2);
        delay(delay1);
      }
      for (int j2 = 110; j2 >= shoulder_angle; j2--){
        shoulder1.write(j2);
        delay(delay1);
      }
      for (int k2 = 130; k2 >= elbow_angle; k2--){
        elbow1.write(k2);
        delay(delay1);
      }
  }
