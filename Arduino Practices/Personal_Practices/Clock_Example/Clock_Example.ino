#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"

// LCD at default I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

void setup() {
  lcd.init();
  lcd.backlight();
  rtc.begin();

  // Uncomment this only ONCE to set the time from compiler
  // rtc.adjust(DateTime(F(_DATE_), F(_TIME_)));

  lcd.setCursor(0, 0);
  lcd.print("Clock Starting");
  delay(1000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  lcd.setCursor(0, 0);
  lcd.print("Time: ");

  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());

  if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");

  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second());

  delay(1000);
}
