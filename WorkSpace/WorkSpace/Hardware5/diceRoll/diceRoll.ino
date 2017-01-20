// diceroll (bd826c54f7f11e549bfd103f6bc1ac43443cc848)
int ledPin[] = {9, 10, 11};
int ledTest = 3;
int button = 2;
byte num = 1;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  pinMode(ledTest, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // for (byte counter=0;counter<=7;counter++)
  // {
  //  displayBinary(counter);
  //  delay(500);
  // }
  if (digitalRead(button) == LOW)
  {
    num = random(0,8);
    Serial.print("high");
  } else displayBinary(num);
  Serial.print(num);
  delay(200);
}

void displayBinary(byte numToShow)
{
  for (int i = 0; i < 4; i++)
  {
    if (bitRead(numToShow, i) == 1)
    {
      digitalWrite(ledPin[i], HIGH);
    }
    else
    {
      digitalWrite(ledPin[i], LOW);
    }
  }
}

