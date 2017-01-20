// btnlight (541e809a03d2981f6615ef73648b1664458b7bd4)
const int button = 2;
const int light = 11;
//const int light = 3;
const int light2 = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(light, OUTPUT);
  pinMode(light2, OUTPUT);
  digitalWrite(light2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  digitalWrite(light, HIGH);
  if (digitalRead(button) == LOW) {
    digitalWrite(light, HIGH);
  } else {
    digitalWrite(light, LOW);
  }
}


