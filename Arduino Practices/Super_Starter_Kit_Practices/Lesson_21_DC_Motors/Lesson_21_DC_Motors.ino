#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void setup() {
  // Set the pin direction:
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);  
}

void loop() {
  // Example of back and forth:
  Serial.println("One way, then reverse");
  digitalWrite(ENABLE, HIGH); // Enable ON
  for (i=0; i<5; i++) {
    digitalWrite(DIRA, HIGH); // One way
    digitalWrite(DIRB, LOW);
    delay(500);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    delay(500);
  }
  digitalWrite(ENABLE, LOW); // Disable
  delay(2000);

  Serial.println("Fast and Slow Example:");
  // Example of Fast/Slow Stop
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  delay(3000);
  digitalWrite(ENABLE, LOW); // Slow Stop
  delay(1000);
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  delay(3000);
  digitalWrite(DIRA, LOW); // Fast Stop
  delay(2000);

  Serial.println("PWM full then slow");
  // PWM Example, Full Speed Then Slow
  analogWrite(ENABLE, 255); // Enable ON
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,50); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,255); //half speed
  delay(2000);
  digitalWrite(ENABLE,LOW); //all done
  delay(10000);
}
