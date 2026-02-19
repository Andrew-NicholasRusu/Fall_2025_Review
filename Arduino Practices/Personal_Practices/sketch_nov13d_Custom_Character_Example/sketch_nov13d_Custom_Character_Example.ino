#include <LiquidCrystal.h>

const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

byte heart [8] = {
  0B00000,0B01010, 0B11111, 0B11111, 
  0B11111, 0B01110, 0B00100, 0B00000  
};

byte smiley[8] = {
  0B0000, 0B0000, 0B01010, 0B0000,
  0B00000, 0B10001, 0B01110, 0B00000
};

byte frownie[8] = {
  0B00000, 0B00000, 0B01010, 0B00000,
  0B00000, 0B00000, 0B01110, 0B10001
};


byte armsDown[8] = {
  0B00100, 0B01010, 0B00100, 0B00100,
  0B01110, 0B10101, 0B00100, 0B01010
};


byte armsUp[8] = {
  0B00100, 0B01010, 0B00100, 0B10101,
  0B01110, 0B00100, 0B00100, 0B01010

};

void setup() {
  lcd.begin (16, 2);
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2,frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);

  lcd.setCursor(0, 0);

  lcd.print("I ");
  lcd.write(byte(0));
  lcd.print(" Arduino! ");
  lcd.write((byte)1);
}

void loop() {
  int sensorReading = analogRead(A0);
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  lcd.setCursor (4, 1);
  lcd.write(3);
  delay(delayTime);
  lcd.setCursor(4, 1);
  lcd.write(4);
  delay(delayTime); 

}













