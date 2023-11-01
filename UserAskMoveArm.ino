#include <Servo.h>

Servo base1;
Servo shoulder1;
Servo elbow1;

int base_pin = 9;
int shoulder_pin = 10;
int elbow_pin = 11;

int base_angle = 90;
int shoulder_angle = 90;
int elbow_angle = 90;

int delay1 = 20;

void leftorrightmove(int angle1){
if (angle1 > base_angle){
for (int i1 = base_angle; i1 <= angle1; i1++){
base1.write(i1);
delay(delay1);
} 
} else if (angle1 < base_angle){
for (int i2 = base_angle; i2 >= angle1; i2--){
base1.write(i2);
delay(delay1);
}
}
}

void sidereturn(int angle2){
if (angle2 > base_angle){
for (int i3 = angle2 ; i3 >= base_angle; i3--){
base1.write(i3);
delay(delay1);
} 
} else if (angle2 < base_angle){
for (int i4 = angle2; i4 <= base_angle; i4++){
base1.write(i4);
delay(delay1);
}
}
}


void forwardmove(int angle3){
if (angle3 > shoulder_angle){
for (int j1 = shoulder_angle; j1 <= angle3; j1++){
shoulder1.write(j1);
delay(delay1);
} 
} else if (angle3 < shoulder_angle){
for (int j2 = shoulder_angle; j2 >= angle3; j2--){
shoulder1.write(j2);
delay(delay1);
}
}
}

void backwardmove(int angle4){
if (angle4 > shoulder_angle){
for (int j3 = angle4 ; j3 >= shoulder_angle; j3--){
shoulder1.write(j3);
delay(delay1);
}
}else if (angle4 < shoulder_angle){
for (int j4 = angle4; j4 <= shoulder_angle; j4++){
shoulder1.write(j4);
delay(delay1);
}
}
}

void precisionforward(int angle5)
{
  
  if (angle5 > elbow_angle)
  {
    for (int k1 = elbow_angle; k1 <= angle5; k1++)
    {
      elbow1.write(k1);
      delay(delay1);
    }
  } 
  
  else if (angle5 <= elbow_angle)
  {
    //Serial.println("Hello");
    for (int k2 = elbow_angle ; k2 >= angle5; k2--)
    {
      elbow1.write(k2);
      delay(delay1);
    }
  }
}


void precisionbackward(int angle6){
if (angle6 > elbow_angle){
for (int k3 = angle6 ; k3 >= elbow_angle; k3--){
elbow1.write(k3);
delay(delay1);
}
}
else if (angle6 <= elbow_angle){
for (int k4 = angle6; k4 <= elbow_angle; k4++){
elbow1.write(k4);
delay(delay1);
}
}
}

void setup(){
base1.attach(base_pin);
shoulder1.attach(shoulder_pin);
elbow1.attach(elbow_pin);

Serial.begin(9600);

int current_base = base1.read();
int current_shoulder = shoulder1.read();
int current_elbow = elbow1.read();

if (current_base != base_angle){
if (current_base > base_angle){
for (int a1 = current_base; a1 >= base_angle; a1--){
shoulder1.write(a1);
delay(delay1);
}
} 
else if (current_base <= base_angle){
for (int a2 = current_base; a2 <= base_angle; a2++){
shoulder1.write(a2);
delay(delay1);
}
}
}

if (current_shoulder != shoulder_angle){
if (current_shoulder > shoulder_angle){
for (int b1 = current_shoulder; b1 >= shoulder_angle; b1--){
shoulder1.write(b1);
delay(delay1);
}
} 
else if (current_shoulder <= shoulder_angle){
for (int b2 = current_shoulder; b2 <= shoulder_angle; b2++){
shoulder1.write(b2);
delay(delay1);
}
}
}

if (current_elbow != elbow_angle){
if (current_elbow > elbow_angle){
for (int c1 = current_elbow; c1 >= elbow_angle; c1--){
shoulder1.write(c1);
delay(delay1);
}
} 
else if (current_elbow <= elbow_angle){
for (int c2 = current_elbow; c2 <= elbow_angle; c2++){
shoulder1.write(c2);
delay(delay1);
}
}
}


}

void loop(){
if (Serial.available()){
Serial.print("Enter angle for base motor: ");
int user_base = Serial.parseInt();
Serial.println(user_base);
Serial.println();
Serial.print("Enter angle for shoulder motor: ");
int user_shoulder = Serial.parseInt();
Serial.println(user_shoulder);
Serial.println();
Serial.print("Enter angle for elbow motor: ");
int user_elbow = Serial.parseInt();
Serial.println(user_elbow);
Serial.println();

leftorrightmove(user_base);
forwardmove(user_shoulder);
precisionforward(user_elbow);

sidereturn(user_base);
backwardmove(user_shoulder);
precisionbackward(user_elbow);
}

int current_base = base1.read();
int current_shoulder = shoulder1.read();
int current_elbow = elbow1.read();

if (current_base != base_angle){
if (current_base > base_angle){
for (int a1 = current_base; a1 >= base_angle; a1--){
shoulder1.write(a1);
delay(delay1);
}
} 
else if (current_base <= base_angle){
for (int a2 = current_base; a2 <= base_angle; a2++){
shoulder1.write(a2);
delay(delay1);
}
}
}

if (current_shoulder != shoulder_angle){
if (current_shoulder > shoulder_angle){
for (int b1 = current_shoulder; b1 >= shoulder_angle; b1--){
shoulder1.write(b1);
delay(delay1);
}
} 
else if (current_shoulder <= shoulder_angle){
for (int b2 = current_shoulder; b2 <= shoulder_angle; b2++){
shoulder1.write(b2);
delay(delay1);
}
}
}

if (current_elbow != elbow_angle){
if (current_elbow > elbow_angle){
for (int c1 = current_elbow; c1 >= elbow_angle; c1--){
shoulder1.write(c1);
delay(delay1);
}
} 
else if (current_elbow <= elbow_angle){
for (int c2 = current_elbow; c2 <= elbow_angle; c2++){
shoulder1.write(c2);
delay(delay1);
}
}
}

}
