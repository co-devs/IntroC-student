// trafficcop (0b94ccfb9e67d8a90b2fbbc810f212976716acee)
const int redLed = 3;
const int yellowLed = 6;
const int greenLed = 10;
const int button = 2;

volatile int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(0, pin_ISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(3000);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(1000);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(3000);
  digitalWrite(redLed, LOW);
}

void pin_ISR() {
  buttonState = digitalRead(button == LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
}

