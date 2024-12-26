int button = 2;
int ledrood = 13;
int ledgroen = 11;
int wachttijd = 0;
int tijd1 = 0;
int tijd2 = 0;
int buttonstate = 0;

void setup() {
  pinMode(button,INPUT);
  pinMode(ledrood,OUTPUT);
  pinMode(ledgroen, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledrood,HIGH);
  delay(10);
  wachttijd = random(0,5000);
  delay(wachttijd);
  
  digitalWrite(ledrood,LOW);
  digitalWrite(ledgroen,HIGH);
  tijd1 = millis();

  while(buttonstate == LOW){
    buttonstate = digitalRead(button);
  }
  tijd2 = millis();  
  Serial.print("reactietijd = ");
  Serial.print(tijd2 - tijd1);
  Serial.println(" ms");

  buttonstate = 0;
  digitalWrite(ledgroen,LOW);
  delay(500);
}
