//morsecode1 (eacd6d2e8abd73c33a0542d6a597853e68b3f52c)
#define BUTTON 2
#define BUZZER 8
#define POTPIN 7
int frequency = 2500;
int dotLen = 50;
int dashLen = dotLen * 3;
int elemPause = dotLen;
int charPause = dotLen * 3;
int wordPause = dotLen * 7;
String stringToMorseCode;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    char received = Serial.read();
    stringToMorseCode += received;

    if (received == '\n')
    {
//      Serial.print("I received: ");
//      Serial.println(stringToMorseCode);
//      Serial.print("string size is: ");
//      Serial.println(stringToMorseCode.length() - 1);
      morseMe();
      Serial.println();
      stringToMorseCode = "";
    }
  }
}

void morseMe()
{
  for (int i = 0; i < stringToMorseCode.length() - 1; i++)
  {
    char tmpChar = stringToMorseCode[i];
    tmpChar = toLowerCase(tmpChar);
    getChar(tmpChar);
    Serial.print(tmpChar);
  }
}

void morseDot()
{
  tone(BUZZER, frequency, dotLen);
  Serial.print('.');
  delay(dotLen);
}

void morseDash()
{
  tone(BUZZER, frequency, dashLen);
  Serial.print('-');
  delay(dashLen);
}

void LightsOff(int delayTime)
{
  noTone(BUZZER);
  delay(delayTime);
}

void getChar(char tmpChar)
{
  switch (tmpChar) {
    case 'a':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'b':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'c':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'd':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'e':
      morseDot();
      LightsOff(charPause);
      break;
    case 'f':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'g':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'h':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'i':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'j':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'k':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'l':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'm':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'n':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'o':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'p':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 'q':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'r':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 's':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case 't':
      morseDash();
      LightsOff(charPause);
      break;
    case 'u':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'v':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'w':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'x':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'y':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case 'z':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case '0':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case '1':
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case '2':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case '3':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case '4':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDash();
      LightsOff(charPause);
      break;
    case '5':
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case '6':
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case '7':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case '8':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case '9':
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDash();
      LightsOff(elemPause);
      morseDot();
      LightsOff(charPause);
      break;
    case ' ':
      LightsOff(wordPause);
      break;
    default:
      // If a matching character was not found it will default to a blank space
      LightsOff(charPause);
  }
}


