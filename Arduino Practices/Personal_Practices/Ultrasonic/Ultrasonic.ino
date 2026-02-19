// Pins
const int trigPin = 7;
const int echoPin = 8;
const int ledPin = 9;

// Global variables 
unsigned long echoTime;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Increase analog read resolution for futrue sensor projects
  analogReadResolution(12); // Now reads 0-4095 instead of 0-1023

  // Increase analog write resolution (if supported by board)
  analogWriteResolution(10); // Now PWM is 0-1023 instead of 0-255
}

void loop() {
  // Example 1: micros() + delayMicroseconds()
  noInterrupts(); // Disable interrupts for critical timing
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH); // Uses precise micro timing
  interrupts(); // Re-enable interrupts

  distance = echoTime / 58; // Convert time to cm

  // Example 2: highByte() and lowByte()
  byte hi = highByte(distance);
  byte lo = lowByte(distance);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm")l

  Serial.print("High Byte: ");
  Serial.println(hi);
  Serial.print("Low Byte: ");
  Serial.println(lo);

  // Example 3: analogWrite with improved resolution
  analogWrite(ledPin, map(distance, 0, 200, 0, 1023));

  // Example 4: bitRead() - check if 4th bit of distance is 1
  if (bitRead(distance, 4) == 1) {
    Serial.println("Bit 4 is ON!");
  }

  // Example 5: isAscii() - check if incoming serial is clean text
  if (Serial.available()) {
    char data = Serial.read();
    if (isAscii(data)) {
      Serial.print("ASCII Received: ");
      Serial.println(data);
    } else {
      Serial.println("Non-ASCII junk ignored.");
    }
  }

  delay(500);
}
