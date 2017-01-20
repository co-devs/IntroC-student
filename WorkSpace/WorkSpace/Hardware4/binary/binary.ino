// binary101 (bbfe353062b8c3e49d7c6838630996f7556ab89e)
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
    if (num == 7)
    {
      num = 0;
    } else {
      num++;
    }
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

