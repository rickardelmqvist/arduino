int iPortButton = 2;
int iPortBlueLed = 3;
int iPortRed1Led = 4;
int iPortRed2Led = 5;

int iBtnState = 0;
int iDelay = 250;

void setup() {

  Serial.begin(9600);
  Serial.println("---- SETUP ----");

  pinMode(iPortButton,INPUT);
  pinMode(iPortBlueLed,OUTPUT);
  pinMode(iPortRed1Led,OUTPUT);
  pinMode(iPortRed2Led,OUTPUT);

  digitalWrite(iPortBlueLed, HIGH);
}

void loop() {
  iBtnState = digitalRead(iPortButton);

  // char str[] = "btnRead: %d";
  // char str2[1000];
  // sprintf(str2,str,iBtnState);
  // Serial.println(str2);

  if(iBtnState == HIGH) {
    Serial.println("-PRESS-");
    digitalWrite(iPortBlueLed, LOW);

    digitalWrite(iPortRed1Led, HIGH);
    digitalWrite(iPortRed2Led, LOW);
    delay(iDelay);

    digitalWrite(iPortRed1Led, LOW);
    digitalWrite(iPortRed2Led, HIGH);
    delay(iDelay);
  }
  else {
    Serial.println("-");
    digitalWrite(iPortBlueLed, HIGH);
    digitalWrite(iPortRed1Led, LOW);
    digitalWrite(iPortRed2Led, LOW);
    delay(2*iDelay);
  }
}
