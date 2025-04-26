//
// Created by painnick on 2025-04-20.
//
#include "PsyduckController.h"

#define MAX_EASING_SERVOS 3
#define ENABLE_EASE_CUBIC

#include "ServoEasing.hpp"

PsyduckController::PsyduckController(const uint16_t pinLeft, const uint16_t pinRight, const uint16_t pinServo) {
    pin_left = pinLeft;
    pin_right = pinRight;

    ch_left = nextChannel++;
    ch_right = nextChannel++;

    ledcSetup(ch_left, 2000, 10);
    ledcSetup(ch_right, 2000, 10);

    ledcAttachPin(pin_left, ch_left);
    ledcAttachPin(pin_right, ch_right);

    servo = new ServoEasing();
    servo->attach(pinServo);
    servo->setEasingType(EASE_CUBIC_OUT);
};

void PsyduckController::headMove(const uint32_t duty) const {
    ledcWrite(ch_right, 0);
    ledcWrite(ch_left, duty);
}


void PsyduckController::tableMove(const int degree, const uint_fast16_t degreesPerSec) const {
    servo->startEaseTo(degree, degreesPerSec);
}
