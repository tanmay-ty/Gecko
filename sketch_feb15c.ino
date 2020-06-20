#include <Servo.h>

Servo myservo;
Servo myservo1;  

char s;    // variable to store the servo position

void setup() {
  myservo1.attach(9);
  myservo.attach(11);// attaches the servo on pin 9 to the servo object
  Serial.begin(38400);
}

void forward()
{
    int i;
    myservo.write(83);
    myservo1.write(107);
}
void brake()
{
  myservo.write(90);
  myservo.write(90);

  myservo1.write(90);
  myservo1.write(90);
}
void backward()
{
    int i;
    myservo1.write(77);
    myservo.write(100);

}
void right()
{           myservo.write(100);

}
void left()
{   int i;
    myservo1.write(67);
}
void hop1()
{
  myservo1.write(110);
  delay(550);
  myservo1.write(90);
  myservo1.write(90);
  myservo.write(0);
  delay(550);
  myservo.write(90);
}
void hop2()
{
  myservo.write(0);
  delay(550);
  myservo.write(90);
  myservo1.write(110);
  delay(550);
  myservo1.write(90);
}
void hop3()
{
  myservo1.write(0);
  delay(550);
  myservo1.write(90);
  myservo1.write(90);
  myservo.write(100);
  delay(850);
  myservo.write(90);
}

void hop4()
{
  myservo.write(100);
  delay(950);
  myservo.write(90);
  myservo.write(90);
  myservo1.write(0);
  delay(550);
  myservo1.write(90);
}
void loop() {
      if(Serial.available()>0)
      { 
          s=Serial.read();
          Serial.println(s);
          switch(s)
          {
            case 'F':
                      brake();
                      forward();
                      break;
            case 'B':
                      brake();
                      backward();
                      break;
            case 'S': 
                      brake();
                      brake();
                      break;
            case 'L':
                      brake();
                      left();
                      break;
            case 'R':
                      brake();
                      right();
                      break;
            case 'G': 
                      brake();
                      hop1();
                      break;
            case 'I':
                      brake();
                      hop2();
                      break;
            case 'H':
                     brake();
                     hop3();
                     break;
            case 'J':
                     brake();
                     hop4();
                     break;
          }
      }
}

