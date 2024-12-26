// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lightBarrierStartPin = A0;
int lightBarrierEndPin = A1;

boolean measuring = false;
long timeAtStart;
long timeAtEnd;

void setup() {
  // pin declaration
  pinMode(lightBarrierStartPin, INPUT);
  pinMode(lightBarrierEndPin, INPUT);
  
  //Serial
  Serial.begin(115200);
  Serial.println();
  Serial.println("Hello lightbarrier expert!");
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("LICHTSLUIZEN!!");
  delay(2000);
}

void loop() {
  int lightBarrierStartState = digitalRead(lightBarrierStartPin);
  int lightBarrierEndState = digitalRead(lightBarrierEndPin);
  
  if(lightBarrierStartState + lightBarrierEndState <2) {
    if(!measuring && lightBarrierStartState == 1) {
      measuring = true;
      timeAtStart = millis();
      Serial.println("Measuring ......");
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("Measuring....");
    }
    
    if(measuring && lightBarrierEndState == 1) {
      measuring = false;
      timeAtEnd = millis();
      long measuredTime = timeAtEnd - timeAtStart;
      Serial.print("Measured time: ");
      Serial.print(measuredTime);
      Serial.println(" millisecond");
      Serial.println();
      
      lcd.setCursor(0, 0);
      lcd.print("Measured....");
      lcd.setCursor(0, 1);
      lcd.print(measuredTime);
      lcd.setCursor(7, 1);
      lcd.print("ms");
    }
    if(measuring) {
      lcd.setCursor(0, 1);
      lcd.print(millis()-timeAtStart);
    }
  }
}

