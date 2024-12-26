/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/AnalogInput

 */
#include <Servo.h>

Servo myServo; 
const int LDR1 = A0;    // select the input pin for the potentiometer
const int LDR2 = A1;
const int potservo = A2; 
int WaardeLDR1 = 0;  // variable to store the value coming from the sensor
int WaardeLDR2 = 0;
int angle = 0;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  WaardeLDR1 = analogRead(LDR1);
  WaardeLDR2 = analogRead(LDR2);
  Serial.print("LDR 1 = ");
  Serial.print(WaardeLDR1 );
  Serial.print(" LDR 2 = ");
  Serial.print(WaardeLDR2);
  Serial.print(" hoek = ");
  Serial.println(angle);
  myServo.write(angle);
  
  delay(500);
  if(WaardeLDR1>WaardeLDR2 && angle < 179){angle = angle + 5;}
  if(WaardeLDR2>WaardeLDR1 && angle > 0){angle = angle - 5;}
}

