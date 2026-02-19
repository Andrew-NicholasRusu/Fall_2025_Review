#include <SoftwareSerial.h>

// Create a software serial connetion for Bluetooth
SoftwareSerial BT(2, 3); // RX = 2, TX = 3

#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600); // USB to PC
  BT.begin(9600); // Bluetooth baud rate (default HC-05/HC-06)

  Serial.println("Bluetooth LED Controller Ready!");
  Serial.println("Send: ON / OFF / TOGGLE");
}

void loop() {
  // Check if data comes from Bluetooth
  if (BT.available()) {
    String command = BT.readStringUntil('\n');
    command.trim(); // remove extra spaces and \r

    Serial.print("Received: ");
    Serial.println(command);

    if (command == "ON") {
      digitalWrite(LED_PIN, HIGH);
      BT.println("LED is ON");
    }
    else if (command == "OFF") {
      digitalWrite(LED_PIN, LOW);
      BT.println("LED is OFF");
    }
    else if (command == "TOGGLE") {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      BT.println("LED toggled");
    }
    else {
      BT.println("Unknown command");
    }
  }
}
