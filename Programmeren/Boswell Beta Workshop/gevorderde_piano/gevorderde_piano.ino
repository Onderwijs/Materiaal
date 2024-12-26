/* piano 
Freek Pols
04/04/2015
*/

#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 392
#define NOTE_G 440

const int speaker = 11;

const int button_c = 2;
const int button_d = 3;
const int button_e = 4;
const int button_f = 5;
const int button_g = 6;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  while (digitalRead(button_c))
    tone(speaker, NOTE_C);
  while (digitalRead(button_d))
    tone(speaker, NOTE_D);
  while (digitalRead(button_e))
    tone(speaker, NOTE_E);
  while (digitalRead(button_f))
    tone(speaker, NOTE_F);
  while (digitalRead(button_g))
    tone(speaker, NOTE_G);    
  noTone(speaker);
}
