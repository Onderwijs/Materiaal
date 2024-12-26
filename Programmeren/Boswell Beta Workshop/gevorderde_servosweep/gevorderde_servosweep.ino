#include <Servo.h>

Servo mijnServo;

int pos = 0;
int i = 1;
int getal =5;

void setup() {
  // put your setup code here, to run once:
 mijnServo.attach(9);
 Serial.begin(9600);
}

void loop() {
 mijnServo.write(10+i);
 delay(100);
 i = i + getal;
 if(i>180||i<0){getal = - getal;}
 Serial.println(i);

}
