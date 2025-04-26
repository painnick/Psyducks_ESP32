//
// Created by painn on 2025-04-20.
//

#ifndef PSYDUCKCONTROLLER_H
#define PSYDUCKCONTROLLER_H

#include "common.h"

class ServoEasing;

class PsyduckController {
  uint8_t ch_left;
  uint8_t pin_left;
  uint8_t ch_right;
  uint8_t pin_right;

  ServoEasing *servo;

  public:
    PsyduckController(uint16_t pinLeft, uint16_t pinRight, uint16_t pinServo);

    void headMove(uint32_t duty) const;


    void tableMove(int degree, uint_fast16_t degreesPerSec) const;
};


#endif //PSYDUCKCONTROLLER_H
