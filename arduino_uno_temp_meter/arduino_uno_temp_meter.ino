const int iSensorPin = A0;
const float fBaselineTemp = 22.0;
const float factor = 0.9;

void setup() {

  Serial.begin(9600);
  Serial.println("---- SETUP ----");

  for(int pinNbr = 2; pinNbr < 5; pinNbr++) {
    pinMode(pinNbr,OUTPUT);
    digitalWrite(pinNbr, LOW);
  }
}

void loop() {
  int iSensorVal = analogRead(iSensorPin);
  float fVoltage = 5 * float(iSensorVal) / 1024 ;
  float fCelcius = (fVoltage - .5) * 100;
  float fDeltaTemp = fCelcius - fBaselineTemp;

  char sOut[1000];
  char sVoltage[6];
  char sCelsius[6]; 
  char sDeltaTemp[6];

  dtostrf( fVoltage, 2, 4, sVoltage );
  dtostrf( fCelcius, 2, 4, sCelsius );
  dtostrf( fDeltaTemp, 2, 4, sDeltaTemp );

  sprintf( sOut, "iSensorVal=%d, fVoltage=%s, fCelcius=%s, fDeltaTemp=%s", iSensorVal, sVoltage, sCelsius, sDeltaTemp);
  Serial.println( sOut );
  delay(500);

  if(fDeltaTemp < 2*factor) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if( fDeltaTemp >= 2*factor && fDeltaTemp < 3*factor) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if( fDeltaTemp >= 3*factor && fDeltaTemp < 4*factor) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if( fDeltaTemp >= 4*factor) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}
