#include <Arduino.h>
#include <TestServo.h>

const int NUM_SERVOS = 5;
const int LAST_TRIGGER = 16;

static int pin[NUM_SERVOS] = { 2, 3, 4, 5, 6};
static int trigger[NUM_SERVOS] = { 1, 2, 4, 8, 16 };
static TestServo *pServo[NUM_SERVOS];

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
  for (int i = 0; i < NUM_SERVOS; ++i) {
    pServo[i] = new TestServo(pin[i]);
  }
}

void loop() {
  static int count = 1;

  for (int index = 0; index < NUM_SERVOS; ++index) {
    if ((count % trigger[index]) == 0) {
      pServo[index]->nextPos();
    }
  }
  ++count;
  if (count > LAST_TRIGGER)
    count = 0;

#ifdef DEBUG
  for (int index = 0; index < NUM_SERVOS; ++index) {
      Serial.print(pServo[index]->getCurrentPos());
      Serial.print("  ");
  }
  Serial.println();
#endif
  delay(1);
}