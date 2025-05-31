//
// Created by painnick on 2025-05-31.
//

#include "PsyduckController.h"

#define PSYDUCK_TAG "psyduck"

constexpr int DEFAULT_SPEED = 5;

#define SERVO_DEFAULT_DEGREE 90
constexpr int SERVO_MIN_DEGREE = SERVO_DEFAULT_DEGREE - 45;
constexpr int SERVO_MAX_DEGREE = SERVO_DEFAULT_DEGREE + 45;

void ServoTargetPositionReachedHandler(ServoEasing *aServoEasingInstance) {
  ESP_LOGD(PSYDUCK_TAG, "Servo[%d] Reached.", aServoEasingInstance->mServoIndex);
  auto lastDegree = aServoEasingInstance->getCurrentAngle();

  START:
  auto degree = (int) random(SERVO_MIN_DEGREE, SERVO_MAX_DEGREE);
  auto distance = lastDegree > degree ? lastDegree - degree : degree - lastDegree;
  if (distance < 30) {
    degree = lastDegree > degree ? lastDegree + 30 : lastDegree - 30;
    if (degree > SERVO_MAX_DEGREE || degree < SERVO_MIN_DEGREE)
      goto START;
    distance = lastDegree > degree ? lastDegree - degree : degree - lastDegree;
  }
  aServoEasingInstance->startEaseTo(degree, DEFAULT_SPEED, START_UPDATE_BY_INTERRUPT);
}

PsyduckController::PsyduckController(int servoPin_, int motorCh1_, int motorCh2_) : servoPin(servoPin_),
                                                                                    motorCh1(motorCh1_),
                                                                                    motorCh2(motorCh2_) {
  servo.attach(servoPin);
  servo.setSpeed(DEFAULT_SPEED);
//  servo.setEasingType(EASE_ELASTIC_IN_OUT);
  servo.setTargetPositionReachedHandler(ServoTargetPositionReachedHandler);
  servo.startEaseTo(SERVO_DEFAULT_DEGREE, DEFAULT_SPEED, START_UPDATE_BY_INTERRUPT);
};

void PsyduckController::headMove(const uint32_t duty) const {
  ledcWrite(motorCh1, 0);
  ledcWrite(motorCh2, duty);
}
