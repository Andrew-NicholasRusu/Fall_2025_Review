// Pin Setup
const int potPin = A0; // Reads the input from the potentiometer
const int motorPin = 9; // Output PWM to motor driver

// Timer variable
unsigned long startTime;
const unsigned long runDuration = 10000; // 10 sec in milliseconds

void setup() {
  pinMode(motorPin, OUTPUT);
  startTime = millis(); // Start timer when program begins
}

void loop() {
  // Read potentiometer (returns 0-1023)
  int potValue = analogRead(potPin); // Reads a sensor vale from 0-1023 (10-bit resolution)

  // Convert range to motor speed (0-255 PWM)
  int motorSpeed = map(potValue, 0, 1023, 0, 255); // Converts a number from one scale to another

  // Time-check using millis()
  unsigned long currentTime = millis();

  if (currentTime - startTime < runDuration) {
    // Run motor normally based on put
    analogWrite(motorPin, motorSpeed); // Controls PWN pins (0-255 duty cycle)
  } else {
    // Stop motor after 10 seconds
    analogWrite(motorPin, 0);
  }
}
