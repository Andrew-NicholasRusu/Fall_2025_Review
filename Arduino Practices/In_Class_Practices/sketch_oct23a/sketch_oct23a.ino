const int potPin=A0;
const int ledPin = 9;
int potValue;
int mappedValue;

void setup(){
  Serial.begin(9600);

}
void loop(){

  potValue=analogRead(potPin);
  Serial.println(potValue);
  mappedValue=map(potValue, 0, 1023, 0, 255);
  Serial.println(mappedValue);
  analogWrite(ledPin, mappedValue);

}