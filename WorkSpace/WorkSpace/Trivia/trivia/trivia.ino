#define GREENBUTTON 8
#define GREENLED 3
#define BLUEBUTTON 7
#define BLUELED 2
const int light = LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:
  pinMode(light, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENBUTTON, INPUT_PULLUP);
  pinMode(BLUEBUTTON, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(GREENBUTTON) == LOW) {
    digitalWrite(light, HIGH);
    digitalWrite(GREENLED,HIGH);
    digitalWrite(BLUELED,LOW);
//    Serial.println("pressed");
  } else if(digitalRead(BLUEBUTTON) == LOW) {
    digitalWrite(light, HIGH);
    digitalWrite(BLUELED,HIGH);
    digitalWrite(GREENLED,LOW);
  } else {
    digitalWrite(light, LOW);
    digitalWrite(GREENLED,LOW);
    digitalWrite(BLUELED,LOW);
  }
  
}
