int redLED = 2;
int greenLED = 4;
int blueLED = 7;

int blinkCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Serial.println("How many times do you want the Red and Green LEDS to blink?");
}

void loop() {
  if (Serial.available() > 0) {
    blinkCount = Serial.parseInt();  

    if (blinkCount > 0) {
      Serial.print("Blinking LEDs ");
      Serial.print(blinkCount);
      Serial.println(" times.");

      blinkLED(blueLED, 1);

      blinkLED(redLED, blinkCount);

      blinkLED(greenLED, blinkCount);

      blinkLED(blueLED, 1);

      Serial.println(" Please enter a new number:");
    }
  }
}

void blinkLED(int ledPin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}