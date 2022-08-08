/*!
 * @file ws_servo.cpp
 *
 * High-level servo manager interface for WipperSnapper.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * @section author Author
 *
 * Written by Brent Rubell for Adafruit Industries, 2022.
 *
 *
 * @section license License
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
#include "ws_servo.h"


/**************************************************************************/
/*!
    @brief  Constructor
*/
/**************************************************************************/
ws_servo::ws_servo() {
  for (int i = 0; i < MAX_SERVO_NUM; i++) {
    _servos[i].pin = 255;
    _servos[i].servoObj = nullptr;
  }

  // TODO: create new instance of ws_ledc_servo for ESP32
}

/**************************************************************************/
/*!
    @brief  Destructor
*/
/**************************************************************************/
ws_servo::~ws_servo() {
/*   for (int i = 0; i < MAX_SERVO_NUM; i++) {
    // de-allocate servo pins, if attached
    if (_servos[i].servoObj->attached())
      _servos[i].servoObj->detach();
  } */
}
