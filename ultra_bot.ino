#include <Servo.h>
Servo myservo;
int enA = 4;
int in1 = 40;
int in2 = 41;
int enB = 5;
int in3 = 42;
int in4 = 43;
byte trig = 13;
byte echo = 12;

byte maxdist = 150; // max sensing dist
byte mindist = 15; // min dist to stop
byte stopdist = 10;
float timeout = 2 * (maxdist + 10) / 100 / 340 * 1000000;
int pos = 0;

byte motorspeed = 50;
//int turnspeed = 45; // amount added when turning
long duration;
int distance;

void setup() {

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trig,OUTPUT); 
  pinMode(echo,INPUT);
  Serial.begin(9600);
  myservo.attach(8);
}
void dist(){ digitalWrite(trig, LOW);
  delayMicroseconds(2); // wait for 2 ms to avoid
  // collision in serial monitor

  digitalWrite(trig, HIGH); // turn on the Trigger to generate pulse
  delayMicroseconds(10); // keep the trigger "ON" for 10 ms to generate
  // pulse for 10 ms.

  digitalWrite(trig,LOW); // Turn off the pulse trigger to stop

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0344 / 2; // Expression to calculate
  // distance using 


//    
}
//void checkdirection() {
//  
//}

void loop() {
  dist();
  if (distance <= mindist) { // motor stop

    Serial.println("turning");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
  }
  delay(300);
  
 
 // Serial.println(distance); // Print the output in serial monitor

  delay(100);

if(distance > mindist) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 110);
  analogWrite(enB, 110);
  Serial.println("forward");
}


int turndir = checkDirection(); //check left and right
Serial.println(turndir);
switch (turndir)
{
case 0 :
  Serial.println("left");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 100);
  analogWrite(enB, 145);
  break;


case 1:
  Serial.println("right");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 140);
  analogWrite(enB, 100);
  break;

}
if (distance <= stopdist) { 
  analogWrite(enA, 0);
analogWrite(enB, 0);
Serial.println("stop");

}

}
