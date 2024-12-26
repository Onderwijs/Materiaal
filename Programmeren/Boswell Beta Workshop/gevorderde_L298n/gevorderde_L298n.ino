int enA = 11;
int in1 = 10;
int in2 = 9;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  brake;
  FSforward;
  brake;
  FSbackward;
}


void brake(){
  digitalWrite(enA,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
}

void FSforward(){
  digitalWrite(enA,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(enA,HIGH);
}

void FSbackward(){
  digitalWrite(enA,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(enA,HIGH);
}
  
  
