#include <Arduino.h>

#include "common.h"

#define MAX_EASING_SERVOS 3
#define DISABLE_COMPLEX_FUNCTIONS
#define ENABLE_EASE_ELASTIC
#define DISABLE_MICROS_AS_DEGREE_PARAMETER

#include <ServoEasing.hpp>
#include "PsyduckController.h"

#define MAIN_TAG "Main"


PsyduckController *duck1, *duck2, *duck3;


void setup() {
  ESP_LOGI(MAIN_TAG, "Setup Table-servo");

  ledcSetup(CH_MOTOR1A, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR1A, CH_MOTOR1A);
  ledcWrite(CH_MOTOR1A, 0);

  ledcSetup(CH_MOTOR1B, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR1B, CH_MOTOR1B);
  ledcWrite(CH_MOTOR1B, 0);

  ledcSetup(CH_MOTOR2A, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR2A, CH_MOTOR2A);
  ledcWrite(CH_MOTOR2A, 0);

  ledcSetup(CH_MOTOR2B, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR2B, CH_MOTOR2B);
  ledcWrite(CH_MOTOR2B, 0);

  ledcSetup(CH_MOTOR3A, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR3A, CH_MOTOR3A);
  ledcWrite(CH_MOTOR3A, 0);

  ledcSetup(CH_MOTOR3B, FREQ_MOTOR, 8);
  ledcAttachPin(PIN_MOTOR3B, CH_MOTOR3B);
  ledcWrite(CH_MOTOR3B, 0);

  ledcSetup(CH_LEDS, 5000, 8);
  ledcAttachPin(PIN_LED1, CH_LEDS);
  ledcAttachPin(PIN_LED2, CH_LEDS);
  ledcAttachPin(PIN_LED3, CH_LEDS);
  ledcWrite(CH_LEDS, 0);

  duck1 = new PsyduckController(PIN_SERVO1, CH_MOTOR1A, CH_MOTOR1B);
  duck2 = new PsyduckController(PIN_SERVO2, CH_MOTOR2A, CH_MOTOR2B);
  duck3 = new PsyduckController(PIN_SERVO3, CH_MOTOR3A, CH_MOTOR3B);
}

void loop() {
  delay(1000);

  double linearValue;
  auto volume = analogRead(PIN_VOLUME); // 0 ~ 4095 (12비트 기준)

  if (volume > 0) {
    // 로그 변환 (기준과 스케일은 실험적으로 조정)
    // linearValue = log(volume); // 자연로그 ln(x)

    // 필요시 정규화 (예: 0~10 범위로 매핑)
    linearValue = (log(volume) - log(1)) / (log(1024) - log(1)) * 10.0;
  } else {
    linearValue = 0; // 0 입력은 로그 정의 안됨
  }

  ledcWrite(CH_LEDS, (linearValue > 11.5f) ? 192 : 0);

  ESP_LOGD(MAIN_TAG, "Volume %4d(%-3.2f)", volume, linearValue);
}
