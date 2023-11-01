#include <Servo.h>

int default_angle = 93;

class motor
{
  public:
  Servo s;
  int res;

  void forward(int angle)
  {
    for(int i=s.read();i<=angle;i++)
    {
      s.write(i);
      delay(45);  
    }
  }

  void backward(int angle)
  {
   for(int i=s.read();i>=angle;i--)
    {
      s.write(i);
      delay(45);  
    }  
  }

  void move1(int angle)
  {
     if (s.read()>angle)
     {
        this->backward(angle); 
     } 
     else if(s.read()<angle)
     {
        this->forward(angle);
     }
  }

  
};

Servo sh,el,ba,wr,cl;

motor shoulder,elbow,base,wrist,claw;

void setup() {
  Serial.begin(9600);
  sh.attach(5);
  el.attach(4);
  ba.attach(3);
  wr.attach(6);
  cl.attach(7);

  shoulder.s=sh;
  elbow.s=el;
  base.s=ba;
  wrist.s=wr;
  claw.s=cl;
  
}


void drop_down_hold()
{
   shoulder.move1(75);
   elbow.move1(140);
   wrist.move1(65);
   claw.move1(10);
}


void bring_up()
{
  shoulder.move1(110);
  elbow.move1(150);
  wrist.move1(50);
}

void drop_down_drop()
{
  wrist.move1(65);
  elbow.move1(140);
  shoulder.move1(75);
  claw.move1(40);
}

void reset()
{
  wrist.move1(default_angle);
  elbow.move1(default_angle);
  shoulder.move1(default_angle);
  claw.move1(default_angle);
  base.move1(default_angle);
}

void loop() 
{
  reset();
  sh.write(93);
  base.move1(60);
  drop_down_hold();
  bring_up();
  base.move1(140);
  drop_down_drop();
  
}
