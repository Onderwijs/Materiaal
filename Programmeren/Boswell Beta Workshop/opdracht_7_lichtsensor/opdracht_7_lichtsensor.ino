int button = 2;
int LDR = A0;
int LED = 11;
int state = 0;
int state1 = 0;
int state2 = 0;
int waardeldr = 0;


void setup() {
  pinMode(LDR,INPUT);
  pinMode(button,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
//  state = digitalRead(button);
  waardeldr = analogRead(LDR);
  delay(10);
  Serial.println(waardeldr);
  druk();
//  if(state == HIGH && state1 == LOW){
//    state2 = HIGH;
//  }
//  
//  if(state == HIGH && state1 == HIGH){
//    state2 = LOW;
//  }
//  state1 = state2;

  if(state2 == HIGH){
    analogWrite(LED,waardeldr/4);
  }
  
  if(state2 == LOW){
    digitalWrite(LED,LOW);
  }
  delay(100);
}


void druk(){
  state = digitalRead(button);
  state2 = state2 + state;
  if(state2 == 2){
    state2 = 0;
  }  
}



