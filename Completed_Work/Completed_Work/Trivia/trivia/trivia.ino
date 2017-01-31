#include <Trivia.h>

#define GREENBUTTON 8
#define GREENLED 3
#define BLUEBUTTON 7
#define BLUELED 2

Trivia trivia(8,7,3,2);

const int light = LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
trivia.question1();
delay(500);
trivia.question2();
delay(500);
trivia.question3();
delay(500);
trivia.question4();
delay(500);
trivia.question5();
delay(500);
  
  
}
