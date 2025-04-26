#pragma once

#include <Arduino.h>

#include "esp_log.h"

// These are all GPIO pins on the ESP32
// Recommended pins include 2,4,12-19,21-23,25-27,32-33
// for the ESP32-S2 the GPIO pins are 1-21,26,33-42

#define PIN_MOTOR1 17
#define PIN_MOTOR2 18
#define PIN_MOTOR3 19
#define PIN_MOTOR4 21
#define PIN_MOTOR5 22
#define PIN_MOTOR6 23

#define PIN_SERVO1 25
#define PIN_SERVO2 33
#define PIN_SERVO3 32

#define CH_MOTOR1 4
#define CH_MOTOR2 5
#define CH_MOTOR3 6
#define CH_MOTOR4 7
#define CH_MOTOR5 8
#define CH_MOTOR6 9

static int nextChannel = 4;
