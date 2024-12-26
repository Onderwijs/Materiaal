int ledgroen = 2;
int ledoranje = 7;
int ledrood = 13;

void setup() {
  pinMode(ledgroen,OUTPUT);
  pinMode(ledoranje,OUTPUT);
  pinMode(ledrood,OUTPUT);
}

void loop() {
  aanuit(ledgroen,1000,100);
  aanuit(ledoranje,1000,100);
  aanuit(ledrood,1000,100);
}

void aanuit(int pin, int duration, int gap){
  digitalWrite(pin,HIGH);
  delay(duration);
  digitalWrite(pin,LOW);
  delay(gap);
}
