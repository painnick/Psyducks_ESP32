#include "common.h"
#include "PsyduckController.h"


#define MAIN_TAG "Main"

PsyduckController *ducks[3];

void setup() {
  ESP_LOGI(MAIN_TAG, "Setup...");

  ducks[0] = new PsyduckController(PIN_MOTOR1, PIN_MOTOR2, PIN_SERVO1);
  ducks[1] = new PsyduckController(PIN_MOTOR3, PIN_MOTOR4, PIN_SERVO2);
  ducks[2] = new PsyduckController(PIN_MOTOR5, PIN_MOTOR6, PIN_SERVO3);

  for (int i = 0; i < 3; i++) {
    ducks[i]->headMove(512 - 1);
  }

  delay(10);

  for (int i = 0; i < 3; i++) {
    ducks[i]->headMove(256 - 1);
  }
}

void loop() {
  ESP_LOGI(MAIN_TAG, "Loop...");

  for (int i = 0; i < 3; i++) {
    ducks[i]->tableMove(0, 10);
  }
  delay(1000 * 18);

  delay(1000 * 2);

  for (int i = 0; i < 3; i++) {
    ducks[i]->tableMove(180, 10);
  }
  delay(1000 * 18);

  delay(1000 * 5);
}
