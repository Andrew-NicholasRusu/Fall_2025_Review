int const analogInPin = A0;
int const digitalOutPin = 9;
int sensorValueIn;
int sensorValueOut;

void setup() {
  Serial.begin(9600);

}

void loop() {
  sensorValueIn = analogRead(analogInPin);
  Serial.println(sensorValueIn);
  delay(1000);

}
