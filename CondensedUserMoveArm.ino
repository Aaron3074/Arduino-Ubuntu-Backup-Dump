#include <Servo.h>

Servo base1;
Servo shoulder1;
Servo elbow1;

int base_pin = 11;
int shoulder_pin = 10;
int elbow_pin = 9;

int base_pose = 90;
int delay1 = 20;

void move(int angle1, int pin_no1){
  //left, back
  if (angle1 > base_pose) {
    Serial.println("Hello angle incrementing");
    for (int i1 = base_pose; i1 <= angle1; i1++){
      switch(pin_no1){
        case 9:
          base1.write(i1);
          delay(delay1);
          break;
        case 10:
          shoulder1.write(i1);
          delay(delay1);
          break;
        case 11:
          elbow1.write(i1);
          delay(delay1);
          break;
        }
    }
  } //right, front 
  else if (angle1 < base_pose){
    Serial.println("Hello angle decrementing");
    for (int i2 = base_pose; i2 >= angle1; i2--){
      switch(pin_no1){
        case 9:
          base1.write(i2);
          delay(delay1);
          break;
        case 10:
          shoulder1.write(i2);
          delay(delay1);
          break;
        case 11:
          elbow1.write(i2);
          delay(delay1);
          break;
      }
    }
  }
}

void home_pose(int pin_no2){
  int current_angle = 0;
  switch(pin_no2){
    case 9:
      current_angle = base1.read();
      break;
    case 10:
      current_angle = shoulder1.read();
      break;
    case 11:
      current_angle = elbow1.read();
      break;
  }
  if (current_angle != base_pose){
    if (current_angle > base_pose){
      Serial.println("Hello2 angle decrementing");
      for (int j1 = current_angle; j1 >= base_pose; j1 --){
        switch (pin_no2){
          case 9:
            base1.write(j1);
            break;
          case 10:
            shoulder1.write(j1);
            break;
          case 11:
            elbow1.write(j1);
            break;
        }
      }
    } else if (current_angle < base_pose){
      Serial.println("Hello2 angle incrementing");
        for (int j2 = current_angle; j2 <= base_pose; j2 ++){
          switch (pin_no2){
          case 9:
            base1.write(j2);
            break;
          case 10:
            shoulder1.write(j2);
            break;
          case 11:
            elbow1.write(j2);
            break;
        }
        }
    }
  }
}

void setup(){
  base1.attach(base_pin);
  shoulder1.attach(shoulder_pin);
  elbow1.attach(elbow_pin);

  Serial.begin(9600);

  home_pose(base_pin);
  home_pose(shoulder_pin);
  home_pose(elbow_pin);
//base1.write(90);
//shoulder1.write(90);
//elbow1.write(90);

}

void loop(){
  if (Serial.available()){
    Serial.print("Enter angle for base motor: ");
    int user_base = Serial.parseInt();
    Serial.println(user_base);

    Serial.print("Enter angle for shoulder motor: ");
    int user_shoulder = Serial.parseInt();
    Serial.println(user_shoulder);

    Serial.print("Enter angle for elbow motor: ");
    int user_elbow = Serial.parseInt();
    Serial.println(user_elbow);

    if (user_base >= 0 && user_base <= 180){
      move (user_base, base_pin);
    } else {
      Serial.println("Base Motor Angle out of range");
    }
    if (user_shoulder >= 0 && user_shoulder <= 180){
      move (user_shoulder, shoulder_pin);
    } else {
      Serial.println("Shoulder Motor Angle out of range");
    }
    if (user_elbow >= 0 && user_elbow <= 180){
      move (user_elbow, elbow_pin);
    } else {
      Serial.println("Elbow Motor Angle out of range");
    }
  }
  home_pose(base_pin);
  home_pose(shoulder_pin);
  home_pose(elbow_pin);
}
