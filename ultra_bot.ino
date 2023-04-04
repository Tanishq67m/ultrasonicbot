#include <Servo.h>

// Define constants
#define trigPin 53
#define echoPin 52
#define servoPin 8  
#define in1 42
#define in2 43
#define in3 41
#define in4 40
#define en2 7
#define en1 6

// Define variables
Servo myservo;
int distance;
int angle = 90;
int mindist=15;
void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Configure pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  // Initialize servo
  myservo.attach(servoPin);

  // Set the initial angle of the servo
  myservo.write(angle);
}

void loop() {
  // Measure the distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH) / 58.2;

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm  ");

  // Check if there is an obstacle within 20 cm
  if (distance < mindist) {
//    // Move the robot backward and turn the servo to avoid the obstacle
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//   analogWrite(en1,100);
//   analogWrite(en2,100);
    if (angle == 90) {
      angle = 0;
    } else if (angle == 0) {
      angle = 85;
    } 
    else if(angle == 85){
      angle = 180; 
    }
    else if(angle == 180){
      angle = 90; 
    }
   
    
    
    
    myservo.write(angle);
  } if(angle==90 && distance>mindist) {
    // Move the robot forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(en1,100);
    analogWrite(en2,100);
    Serial.print("forward");
    
  }
  if(angle==0 && distance>mindist) {
    // Move the robot right
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(en1,100);
    analogWrite(en2,140);
    Serial.print("right");
  }
  if(angle==180 && distance>mindist) {
    // Move the robot left
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(en1, 140);
    analogWrite(en2, 100);
    Serial.print("left");
    
    
  }//delay(2000);
//  if(angle!=90){
//    angle=90;
//  }
  
  // Wait for 200ms before measuring the distance again
  delay(200);
  Serial.print("   ");
  Serial.println(angle);

  
}
