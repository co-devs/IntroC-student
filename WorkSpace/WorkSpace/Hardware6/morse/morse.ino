int button = 2;
int buzzer = 8;
int frequency = 1000;
int dotLen = 50;
int dashLen = dotLen * 3;
int elemPause = dotLen;
int charPause = dotLen * 3;
int wordPause = dotLen * 7;
char stringToMorseCode[] = "Breaking news germany invades france british forces begin mobilizing us president denounces german aggression";

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    char tmpChar = stringToMorseCode[i];
    tmpChar = toLowerCase(tmpChar);
    getChar(tmpChar);
    Serial.print(tmpChar);
  }
  LightsOff(8000);
}

void morseDot()
{
  tone(buzzer, frequency, dotLen);
  delay(dotLen);
}

void morseDash()
{
  tone(buzzer, frequency, dashLen);
  delay(dashLen);
}

void LightsOff(int delayTime)
{
  noTone(buzzer);
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
    case ' ':
      LightsOff(wordPause);
      break;
    default:
      // If a matching character was not found it will default to a blank space
      LightsOff(charPause);
  }
}


