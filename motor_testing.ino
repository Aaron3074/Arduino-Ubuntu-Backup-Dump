//const int in1 = 10;
//const int in2 = 11;
//const int in3 = 12;
//const int in4 = 13;
////const int enA = ;
////const int enB = ;
//
//void setup() {
//  pinMode(in1, INPUT);
//  pinMode(in2, INPUT);
//  pinMode(in3, INPUT);
//  pinMode(in4, INPUT);
//  //pinMode(enA, OUTPUT);
//  //pinMode(enB, OUTPUT):
//}
//
//void loop() {
//  //analogWrite(enA, 150);
//  //analogWrite(enB, 150);
//  digitalWrite(in1, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in4, LOW);
//
//}

const int in1 = 10;
const int in2 = 11;
const int in3 = 12;
const int in4 = 13;
const int encoderPin1 = 2;
const int encoderPin2 = 3;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder, CHANGE);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
//  Serial.print("Encoder Value: ");
//  Serial.println(encoderValue);
//  delay(2000);
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH);
//  Serial.print("Encoder Value: ");
//  Serial.println(encoderValue);
//  delay(2000);
  Serial.print("Encoder Value: ");
  Serial.println(encoderValue);

  delay(1000);
}

void updateEncoder() {
  int MSB = digitalRead(encoderPin1);
  int LSB = digitalRead(encoderPin2);
  int encoded = (MSB << 1) | LSB;
  int sum = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    encoderValue--;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    encoderValue++;

  lastEncoded = encoded;
}
