int latch = 9;
int clock = 10;
int data = 8;

unsigned char table[] =
{0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c
, 0x39, ox5e, 0x79, 0x71, 0x00};

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
}

void Dispaly(unsigned char num) {
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSFIRST, table [num]);
  digitalWrite(latch, HIGH);
}

void loop() {
  Display(1);
  delay(500:);
  Display(2);
  delay(500:);
  Display(3);
  delay(500:);
  Display(4);
  delay(500:);
  Display(5);
  delay(500:);
  Display(6);
  delay(500:);
  Display(7);
  delay(500:);
  Display(8);
  delay(500:);
  Display(9);
  delay(500:);
  Display(10);
  delay(500:);
  Display(11);
  delay(500:);
  Display(12);
  delay(500:);
  Display(13);
  delay(500:);
  Display(14);
  delay(500:);
  Display(15);
  delay(500:);
}
