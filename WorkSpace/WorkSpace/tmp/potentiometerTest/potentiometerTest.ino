#define POTPIN 7
#define BUZZER 8
int freq = 2500;

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(57600);
}
void loop() {
  if(switchPushed() == true)
  {
    freq = map(analogRead(POTPIN), 0, 1023, 303, 14500);
    tone(BUZZER, freq);
    Serial.println(freq);
    delay(200);
    noTone(BUZZER);
  }
}

boolean switchPushed() {
  static const int pushButtonSwitch = 2; // switch is on pin D2, declare as constant, hide from other functions
  pinMode(pushButtonSwitch, INPUT_PULLUP); // D2 INPUT mode and attach a PULLUP resistor
  if(digitalRead(pushButtonSwitch) == HIGH) return false; // if 5v (HIGH) switch is NOT pushed
  else return true;
// if 0v (LOW) switch IS pushed
}
