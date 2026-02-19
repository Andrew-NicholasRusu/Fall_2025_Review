#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11
#define DHTpin 8
DHT dht(DHTpin, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  float h =dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.print("°C");
  Serial.print(f);
  Serial.println("°F");

}
