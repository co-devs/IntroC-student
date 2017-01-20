String myStr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    char received = Serial.read();
    myStr += received;

    if (received == '\n')
    {
      Serial.print("I received: ");
      Serial.println(myStr);
      Serial.print("sizeof is: ");
      Serial.println(sizeof(myStr));
      Serial.print("length is: ");
      Serial.println(myStr.length());

      myStr = "";
    }
  }
}
