#include <SPI.h>
#include <SD.h>

Sd2Card card;
SdVolume volume;
SdFile root;

const int CS_pin = 4;


// Not use, A4&A5, 10,11,12,13
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing card");
  pinMode(4, OUTPUT);

  
 
  if(!SD.begin(CS_pin)){
    Serial.println("Card failure"); 
    return;
  }
  
  Serial.println("Card ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  long timeStamp = millis();
  String dataString = "Hello World!";
  
  File dataFile = SD.open("log.csv", FILE_WRITE);
  if(dataFile)
   {
    dataFile.print(timeStamp);
    dataFile.print(",");
    dataFile.println(dataString);
    dataFile.close();
   
    Serial.print(timeStamp);
    Serial.print(", ");
    Serial.println(dataString);
   }
  else
   {
     Serial.println("couldnt open log file");
   }
   delay(500);
}
