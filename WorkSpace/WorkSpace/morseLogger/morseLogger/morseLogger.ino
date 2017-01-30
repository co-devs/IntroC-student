#define BUTTON 2
static int dotLen = 50;
static int dashLen = dotLen * 3;
static int elemPause = dotLen;
//static int charPause = dotLen * 3;
//static int wordPause = dotLen * 7;
static int charPause = dotLen * 1;
static int wordPause = dotLen * 2;
int pause = 0;
int letter [5];
int index = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean pushed;
  pushed = switchPushed();
  int duration = 0;
  
  while(pushed == true)
  {
    // do something
//    Serial.print("+");
    pushed = switchPushed();
    duration++;
    pause = 0;
    delay(10);
  }
  if (duration <= dotLen && duration > 1) {
//    Serial.println("DOT");
    letter[index] = 1;
//    printArray(letter);
    index++;
  } else if (duration > dotLen) {
//    Serial.println("DASH");
    letter[index] = 2;
//    printArray(letter);
    index++;
  }

  if (pause > wordPause) {
    Serial.print("_");
    pause = 0;
//    Serial.println("end word");
//    printArray(letter);
  } else if (pause > elemPause) {
    index = 0;
    if (letter[0] != 0) {
//      do letter, otherwise empty and do nothing
      evalLetter(letter);
//      Serial.println("end letter");
//      printArray(letter);
    }
    memset(letter, 0, sizeof(letter));
  }
  if (index > 4) {
    index = 0;
    evalLetter(letter);
    memset(letter, 0, sizeof(letter));
  }
//  Serial.println(pause);
  pause++;
  duration = 0;
  delay(dotLen);
//  Serial.println("button off");
}

boolean switchPushed() {
  if(digitalRead(BUTTON) == HIGH) return false;
  else return true;
}

void printArray(int myArr[5]) {
  for (int i;i<5;i++) {
    Serial.print(myArr[i]);
  }
  Serial.println();
}

void evalLetter(int myArr[5]) {
  char intStr[6];
  int i = 0;
  int index = 0;
  for (i=0;i<5;i++) {
    index += sprintf(&intStr[index], "%d", myArr[i]);
  }
  intStr[5]=0;
//  Serial.print("Word is ");
//  Serial.println(intStr);
  if (strcmp(intStr, "12000") == 0) {
    Serial.print('A');
  } else if (strcmp(intStr, "21110") == 0) {
    Serial.print('B');
  } else if (strcmp(intStr, "21210") == 0) {
    Serial.print('C');
  } else if (strcmp(intStr, "21100") == 0) {
    Serial.print('D');
  } else if (strcmp(intStr, "10000") == 0) {
    Serial.print('E');
  } else if (strcmp(intStr, "11210") == 0) {
    Serial.print('F');
  } else if (strcmp(intStr, "22100") == 0) {
    Serial.print('G');
  } else if (strcmp(intStr, "11110") == 0) {
    Serial.print('H');
  } else if (strcmp(intStr, "11000") == 0) {
    Serial.print('I');
  } else if (strcmp(intStr, "12220") == 0) {
    Serial.print('J');
  } else if (strcmp(intStr, "21200") == 0) {
    Serial.print('K');
  } else if (strcmp(intStr, "12110") == 0) {
    Serial.print('L');
  } else if (strcmp(intStr, "22000") == 0) {
    Serial.print('M');
  } else if (strcmp(intStr, "21000") == 0) {
    Serial.print('N');
  } else if (strcmp(intStr, "22200") == 0) {
    Serial.print('O');
  } else if (strcmp(intStr, "12210") == 0) {
    Serial.print('P');
  } else if (strcmp(intStr, "22120") == 0) {
    Serial.print('Q');
  } else if (strcmp(intStr, "12100") == 0) {
    Serial.print('R');
  } else if (strcmp(intStr, "11100") == 0) {
    Serial.print('S');
  } else if (strcmp(intStr, "20000") == 0) {
    Serial.print('T');
  } else if (strcmp(intStr, "11200") == 0) {
    Serial.print('U');
  } else if (strcmp(intStr, "11120") == 0) {
    Serial.print('U');
  } else if (strcmp(intStr, "11120") == 0) {
    Serial.print('V');
  } else if (strcmp(intStr, "12200") == 0) {
    Serial.print('W');
  } else if (strcmp(intStr, "21120") == 0) {
    Serial.print('X');
  } else if (strcmp(intStr, "21220") == 0) {
    Serial.print('Y');
  } else if (strcmp(intStr, "22110") == 0) {
    Serial.print('Z');
  } else if (strcmp(intStr, "22222") == 0) {
    Serial.print('0');
  } else if (strcmp(intStr, "12222") == 0) {
    Serial.print('1');
  } else if (strcmp(intStr, "11222") == 0) {
    Serial.print('2');
  } else if (strcmp(intStr, "11122") == 0) {
    Serial.print('3');
  } else if (strcmp(intStr, "11112") == 0) {
    Serial.print('4');
  } else if (strcmp(intStr, "11111") == 0) {
    Serial.print('5');
  } else if (strcmp(intStr, "21111") == 0) {
    Serial.print('6');
  } else if (strcmp(intStr, "22111") == 0) {
    Serial.print('7');
  } else if (strcmp(intStr, "22211") == 0) {
    Serial.print('8');
  } else if (strcmp(intStr, "22221") == 0) {
    Serial.print('9');
  } else {
    Serial.println("not found");
  }
}

