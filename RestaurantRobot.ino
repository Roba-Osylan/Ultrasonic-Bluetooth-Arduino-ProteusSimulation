#include <Servo.h> //include the servo library 
#include <SoftwareSerial.h>
//Servo
//Define the pins of each servo
#define pinServo1R 6 //right arm
#define pinServo2R 5
#define pinServo3R 3
#define pinServo4L 9 //left arm
#define pinServo5L 10
#define pinServo6L 11
//Create servo objects
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

//Ultrasonic
const int trigPin = 12;  //define trigger pin  
const int echoPin = 8;  //define echo pin connection 
float duration, distance;
//Vertual terminal
SoftwareSerial mySerial(1,0);

void setup() {
pinMode(13, OUTPUT);
digitalWrite(13,LOW);   
Serial.begin(9600);  
                                             
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

  //attach each servo with its defined pin
  Servo1.attach(pinServo1R);
  Servo2.attach(pinServo2R);
  Servo3.attach(pinServo3R);
  Servo4.attach(pinServo4L);
  Servo5.attach(pinServo5L);
  Servo6.attach(pinServo6L);
}

void loop() {
 //Clear trigger pin for 2 microseconds
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
//then generate the ultrasound wave for 3 seconds
digitalWrite(trigPin, HIGH);
delay(3000);
digitalWrite(trigPin, LOW);

//read the travel time from the echo pin (reciever)
duration = pulseIn(echoPin, HIGH); //measure the duration of the high pulse
distance= (duration/2) * 0.034;   //calculate the distance in cm using the result of the previus instruction

mySerial.print("Hi, this is a simulation test");

if (distance >53 || distance <=2) {
  mySerial.println("Out of Range");
  digitalWrite(13,LOW);
  
  Servo1.write(0); //the top rhight and left servos
  Servo4.write(0);
  delay(1500);      //wait for 1.5 s
  Servo2.write(0); //the middle rhight and left servos
  Servo5.write(0);
  delay(1500);      //wait for 1.5 s
  Servo3.write(0); // the buttom rhight and left servos
  Servo6.write(0); 
  }
  else {
  digitalWrite(13,HIGH);
  mySerial.print(distance);
  mySerial.println("  cm");
  //Rotate the servos with initial angle of 90 degree
  Servo1.write(90); //the top rhight and left servos
  Servo4.write(90);
  delay(1500);      //wait for 1.5 s
  Servo2.write(45); //the middle rhight and left servos
  Servo5.write(45);
  delay(1500);      //wait for 1.5 s
  Servo3.write(0); // the buttom rhight and left servos
  Servo6.write(0);
  delay(1500);      //wait for 1.5 s
  }
}
