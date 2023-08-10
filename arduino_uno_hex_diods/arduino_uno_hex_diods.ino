int ports[4] = {13,12,11,10};
int iDelay = 1000;

void setup() {
  Serial.begin(9600);
  Serial.println("---- SETUP ----");
  for(int i; i < 4; i++) {
    pinMode(ports[i], OUTPUT);
  }

}

bool* decToBin(int num) {

  static bool binaryNum[4];

  int temp = num;
  int pos = 0;
  while(temp > 0 && pos < 4) {
    binaryNum[pos] = ( (temp % 2) > 0 );
    temp = temp / 2;
    pos++;
  }
  return binaryNum;
}

void loop() {
  for(int i = 0; i < 16; i++) {
    bool* arrBin = decToBin(i);
    
    digitalWrite(ports[0],arrBin[0] ? HIGH: LOW);
    digitalWrite(ports[1],arrBin[1] ? HIGH: LOW);
    digitalWrite(ports[2],arrBin[2] ? HIGH: LOW);
    digitalWrite(ports[3],arrBin[3] ? HIGH: LOW);
    
    char str[] = "%d:[%d%d%d%d]";
    char str2[1000];
    sprintf(str2,str,i,arrBin[0],arrBin[1],arrBin[2],arrBin[3]) ;
    Serial.println(str2);
    
    delay(iDelay);
    arrBin[0] = false;
    arrBin[1] = false;
    arrBin[2] = false;
    arrBin[3] = false;
  }
}
