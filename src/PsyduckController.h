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

  ServoEasing servo;

 public:
  PsyduckController(int servoPin_, int motorCh1_, int motorCh2_);

  void headMove(uint32_t duty) const;
};


#endif //PSYDUCK_ESP32_SRC_PSYDUCKCONTROLLER_H_
