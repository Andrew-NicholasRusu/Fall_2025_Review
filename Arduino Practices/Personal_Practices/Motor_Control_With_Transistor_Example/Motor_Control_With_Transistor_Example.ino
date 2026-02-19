int pushButton = 2;
int motorControl = 9;

void setup() {
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);

  // make the transistor's pin an output:
  pinMode(motorControl, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the state of the button and check if it is pressed.
  if (digitalRead(pushButton) == HIGH) {
    // ramp uup the motor speed
    for (int x = 0; x <= 255; x++) {
      analogWrite(motorControl, x);
      delay(50);
    }

    // ramp down the motor speed
    for (int x = 255; x >= 0; x--) {
      analogWrite(motorControl, x);
      delay(50);
    }
  }

  delay(1); // delay in between reads for stability
}
