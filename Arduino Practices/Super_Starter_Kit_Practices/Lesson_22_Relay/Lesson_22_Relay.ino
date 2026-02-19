#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void setup() {
  //--- Set the pin direction.
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // Example of Back and Forth
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE, HIGH); // Enable On
    for (i = 0; i < 5; i++) {
      digitalWrite(DIRA, HIGH); // One way
      digitalWrite(DIRB, LOW);
      delay(750);
      digitalWrite(DIRA, LOW); // Reverse
      digitalWrite(DIRB, HIGH);
      delay(750);
    }
    digitalWrite(ENABLE, LOW); // Disable
      delay(3000);
        for (i = 0; i < 5; i++) {
      digitalWrite(DIRA, HIGH); // One way
      digitalWrite(DIRB, LOW);
      delay(750);
      digitalWrite(DIRA, LOW); // Reverse
      digitalWrite(DIRB, HIGH);
      delay(750);
    }
      digitalWrite(ENABLE, LOW); // Disable
      delay(3000);
}
