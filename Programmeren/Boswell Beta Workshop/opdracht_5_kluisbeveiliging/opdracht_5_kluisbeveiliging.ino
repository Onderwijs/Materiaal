int knop1 = 2;
int knop2 = 3;
int ledpin = 9;

int toestandknop2 = 1;
int toestandknop1 = 1;

void setup(){
 pinMode(ledpin,OUTPUT);
 pinMode(knop1,INPUT);
 pinMode(knop2,INPUT);
}

void loop(){
   toestandknop1 = digitalRead(knop1);
   toestandknop2 = digitalRead(knop2);
   if(toestandknop1 == HIGH && toestandknop2 == HIGH){digitalWrite(ledpin,HIGH);}
   else{digitalWrite(ledpin,LOW);}
   delay(100);
}

