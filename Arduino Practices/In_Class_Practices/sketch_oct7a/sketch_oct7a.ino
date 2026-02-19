const int ledPin = 7;

void setup() {
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("LED ON");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  Serial.println("LED OFF");
  digitalWrite(ledPin, LOW);
  delay(1000);
}

