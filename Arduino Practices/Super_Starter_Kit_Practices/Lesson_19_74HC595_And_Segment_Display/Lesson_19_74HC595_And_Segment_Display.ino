byte seven_seg_digits[10] = { B11111100, 
                              B01100000,
                              B11011010,
                              B11110010,
                              B01100110,
                              B10111110,
                              B11100000,
                              B11111110,
                              B11100110
                              };
// Connect to the ST_CP OF 74HC595 ( pin 3, latch pin)
int latchPin = 3;
// Connect to the SH_CP of 74HC95 (pin 4, clock pin)
int clockPin = 4;
// Connect to the DS of 74HC595 (pin 2)
int dataPin = 2;

void setup() {
  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// Display a number on the digital segment display
void sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);

  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);

  // set the latchpin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // count from 9 to 0
  for (byte digit = 10; digit > 0; --digit) {
    delay(1000);
    sevenSegWrite(digit - 1);
  }

  // Suspend 4 seconds
  delay (3000);
}









