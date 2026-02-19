#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
#define DHTpin 8
DHT dht(DHTpin, DHTTYPE);

const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int ledPin = 8;
int buttonPin = 7;
int buttonPin2 = 6;
int potPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.print("°C");
  Serial.print(f);
  Serial.println("°F");

  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);

  lcd.setCursor(0, 0);
  lcd.print("Bright: ");
  lcd.print(brightness);

  lcd.setCursor(0, 1);
  if (digitalRead(buttonPin) == LOW) {
    lcd.print("Button Pressed  ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("ButtonNotPressed: ");
  }

  Serial.println(potValue);

  delay(100);
}
