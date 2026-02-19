int input;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println("Enter 1 to turn LED ON and Enter 0 to turn LED OFF");
  while(Serial.available()==0) {

  }
  input=Serial.parseInt();
  if(input==1){
    Serial.println("LED ON");
    digitalWrite(ledPin, HIGH);


  }
  else{
    Serial.println("LED OFF");
    digitalWrite(ledPin, LOW);

  }

}
