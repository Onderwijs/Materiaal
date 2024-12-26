/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
int knop2 = 2;     // the number of the pushbutton pin
int knop1 = 3;     // the number of the pushbutton pin
int ledPin =  9;      // the number of the LED pin
int toestandKnop2 = 0;
int toestandKnop1 = 0;

int state = HIGH;
int state1 = HIGH;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(knop2, INPUT);
  pinMode(knop1, INPUT);
}

void loop() {
  toestandKnop2 = digitalRead(knop2);  //'lees' de waarde op pin2
  toestandKnop1 = digitalRead(knop1);
  Serial.println(toestandKnop2);       //laat de waarde van 2 zien op de monitor
  
  if(state == HIGH && toestandKnop2 == HIGH || toestandKnop1 == HIGH){state1 = LOW;}
  if(state == LOW && toestandKnop2 == HIGH || toestandKnop1 == HIGH){state1 = HIGH;}
  
 
  digitalWrite(ledPin, state1);
  state = state1;
  delay(100);
  
}
  
 
