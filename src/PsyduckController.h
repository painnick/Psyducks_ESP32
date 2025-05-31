//
// Created by painnick on 2025-05-31.
//

#ifndef PSYDUCK_ESP32_SRC_PSYDUCKCONTROLLER_H_
#define PSYDUCK_ESP32_SRC_PSYDUCKCONTROLLER_H_

#define SUPPRESS_HPP_WARNING

#include <ServoEasing.h>

class PsyduckController {
  int servoPin;
  int motorCh1, motorCh2;
  bool isMotor1;

  ServoEasing servo;

 public:
  PsyduckController(int servoPin_, int motorCh1_, int motorCh2_);

  void headMove(uint32_t duty) const;

  void headMove1(uint32_t duty) const;

  void headMove2(uint32_t duty) const;

  void changeDirection() { isMotor1 = !isMotor1; };
};


#endif //PSYDUCK_ESP32_SRC_PSYDUCKCONTROLLER_H_
