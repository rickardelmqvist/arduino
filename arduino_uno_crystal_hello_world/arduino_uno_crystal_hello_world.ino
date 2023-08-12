#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  Serial.println("---- SETUP ----");

  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  int iMillis = (millis() / 1000);
  lcd.setCursor(0, 1);
  lcd.print(iMillis);
  Serial.println(iMillis);
  delay(1000);
}


