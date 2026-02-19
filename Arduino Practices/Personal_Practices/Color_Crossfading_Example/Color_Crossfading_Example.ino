// Output
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Color arrays
int black[3] = { 0, 0, 0 };
int white[3] = { 100, 100, 100 };
int red[3] = { 100, 0, 0 };
int green[3] = { 0, 100, 0 };
int blue[3] = { 0, 0, 100 };
int yellow[3] = { 40, 95, 0};
int dimWhite[3] = { 30, 30, 30 };

// Set initial color
int redVal = black[0];
int greenVal = black[1];
int blueVal = black[2];

int wait = 10;
int hold = 0;
int DEBUG = 1;
int loopCount = 60;
int repeat = 3;
int j = 0;

// Initialize color variables
int prevR = redVal;
int prevG = greenVal;
int prevB = blueVal;

// Set up the LED outputs
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  if (DEBUG) {
    Serial.begin(9600);
  }
}

// Main program: list the order of crossfades
void loop() {
  crossFade(red);
  crossFade(green);
  crossFade(blue);
  crossFade(yellow);

  if (repeat) { // Do we loop a finite number of times?
    j += 1;
    if (j >= repeat) { // Are we there yet?
      exit(j);         // If so, stop.
    }
  }
}

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue;
  if (step) {
    step = 1020/step;
  }
  return step;
}

int calculateVal(int step, int val, int i) {
  if ((step) && i % step == 0) {
    if (step > 0) {
      val += 1;
    }
    else if (step < 0) {
      val -= 1;
    }
  }
  // Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  }
  else if (val < 0) {
    val = 0;
  }
  return val;
}

/* crossFade() covners the percentage colors to a 0-255 range, then loops 1020
* times, checking to see if the value needs to be updated each time, then writing 
* the color values to the correct pins.
*/

void crossFade(int color[3]) {
  // Convert to 0-255
  int R = (color[0] * 255) / 100;
  int G = (color[1] * 255) / 100;
  int B = (color[2] * 255) / 100;

  int stepR = calculateStep(prevR, R);
  int stepG = calculateStep(prevG, G);
  int stepB = calculateStep(prevB, B);

  for (int i = 0; i <= 1020; i++) {
    redVal = calculateVal(stepR, redVal, i);
    greenVal = calculateVal(stepG, greenVal, i);
    blueVal = calculateVal(stepB, blueVal, i);

    analogWrite(redPin, redVal);
    analogWrite(greenPin, greenVal);
    analogWrite(bluePin, blueVal);

    delay(wait); // Pause for 'wait' milliseconds before resuming the loop

    if (DEBUG) {
      if (i == 0 or i % loopCount == 0) {
        Serial.print("Loop/RGB: #");
        Serial.print(i);
        Serial.print(" | ");
        Serial.print(redVal);
        Serial.print(" / ");
        Serial.print(greenVal);
        Serial.print(" / ");
        Serial.println(blueVal);
      }
      DEBUG += 1;
    }
  }
  // Update current values for next loop
  prevR = redVal;
  prevG = greenVal;
  prevB = blueVal;
  delay(hold); // Pause for optional 'wait' milliseconds before the loop
}


