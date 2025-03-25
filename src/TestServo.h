#ifndef TEST_SERVO_H
#define TEST_SERVO_H

#include <Servo.h>

class TestServo : public Servo {
    private:
        static const int MIN_MICROS = 1000;
        static const int MAX_MICROS = 2000;

        int currentPos;
        int inc;
    public:
        TestServo(int pin);
        void nextPos();
        int getCurrentPos();

};

#endif
