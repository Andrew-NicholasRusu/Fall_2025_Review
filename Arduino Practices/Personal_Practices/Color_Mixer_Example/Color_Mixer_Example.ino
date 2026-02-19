int potPin = A3;
int potVal = 0;

int redPin = 9; // Red LED, connected to digital pin 9
int greenPin = 10; // Green LED, connected to digital pin 10
int bluePin = 11; // Blue LED, connected to digital pin 11

int redVal = 0; // Variables to store the values to send to the pins
int greenVal = 0;
int blueVal = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);

  if (potVal < 341) 
  {
    potVal = (potVal * 3) / 4;

    redVal = 256 - potVal;
    greenVal = potVal;
    blueVal = 1;
  }
  else if (potVal < 682) {
    potVal = ( (potVal - 341) * 3) / 4;

    redVal = 1;
    greenVal = 256 - potVal;
    blueVal = potVal;
  }
  else 
  {
    potVal = ( (potVal - 683) * 3) / 4;

    redVal = potVal;
    greenVal = 1;
    blueVal = 256 - potVal;
  }
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
