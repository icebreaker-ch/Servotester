#include "TestServo.h"

TestServo::TestServo(int pin) :
    currentPos((MAX_MICROS + MIN_MICROS) / 2),
    inc(1) {
    attach(pin);
    writeMicroseconds(currentPos);
}

void TestServo::nextPos() {
    if (currentPos >= MAX_MICROS)
        inc = -1;
    else if (currentPos <= MIN_MICROS)
        inc = 1;
    currentPos += inc;
    writeMicroseconds(currentPos);
}

int TestServo::getCurrentPos() {
    return currentPos;
}
