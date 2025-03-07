/*!
 * @file WipperSnapper_I2C_Driver_BMP3XX.h
 *
 * Device driver for a BMP3XX precision pressure sensor breakout.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Tyeth Gundry 2023 for Adafruit Industries.
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */

#ifndef WipperSnapper_I2C_Driver_BMP3XX_H
#define WipperSnapper_I2C_Driver_BMP3XX_H

#include "WipperSnapper_I2C_Driver.h"
#include <Adafruit_BMP3XX.h>

#define SEALEVELPRESSURE_HPA (1013.25) ///< Default sea level pressure, in hPa

/**************************************************************************/
/*!
    @brief  Class that provides a sensor driver for the BMP3XX temperature
            and pressure sensor.
*/
/**************************************************************************/
class WipperSnapper_I2C_Driver_BMP3XX : public WipperSnapper_I2C_Driver {

public:
  /*******************************************************************************/
  /*!
      @brief    Constructor for an BMP3XX sensor.
      @param    i2c
                The I2C interface.
      @param    sensorAddress
                7-bit device address.
  */
  /*******************************************************************************/
  WipperSnapper_I2C_Driver_BMP3XX(TwoWire *i2c, uint16_t sensorAddress)
      : WipperSnapper_I2C_Driver(i2c, sensorAddress) {
    _i2c = i2c;
    _sensorAddress = sensorAddress;
  }

  /*******************************************************************************/
  /*!
      @brief    Destructor for an BMP3XX sensor.
  */
  /*******************************************************************************/
  ~WipperSnapper_I2C_Driver_BMP3XX() { delete _bmp3xx; }

  /*******************************************************************************/
  /*!
      @brief    Initializes the BMP3XX sensor and begins I2C.
      @returns  True if initialized successfully, False otherwise.
  */
  /*******************************************************************************/
  bool begin() {
    _bmp3xx = new Adafruit_BMP3XX();
    // attempt to initialize BMP3XX
    if (!_bmp3xx->begin_I2C(_sensorAddress, _i2c))
      return false;

    // Set up oversampling and filter initialization
    _bmp3xx->setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    _bmp3xx->setPressureOversampling(BMP3_OVERSAMPLING_4X);
    _bmp3xx->setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    _bmp3xx->setOutputDataRate(BMP3_ODR_50_HZ);

    return true;
  }

  /*******************************************************************************/
  /*!
      @brief    Gets the BMP3XX's current temperature.
      @param    tempEvent
                Pointer to an Adafruit_Sensor event.
      @returns  True if the temperature was obtained successfully, False
                otherwise.
  */
  /*******************************************************************************/
  bool getEventAmbientTemp(sensors_event_t *tempEvent) {
    if (!_bmp3xx->performReading())
      return false;
    tempEvent->temperature = _bmp3xx->temperature;
    return true;
  }

  /*******************************************************************************/
  /*!
      @brief    Reads a pressure sensor and converts
                the reading into the expected SI unit.
      @param    pressureEvent
                Pointer to an Adafruit_Sensor event.
      @returns  True if the sensor event was obtained successfully, False
                otherwise.
  */
  /*******************************************************************************/
  bool getEventPressure(sensors_event_t *pressureEvent) {
    if (!_bmp3xx->performReading())
      return false;
    pressureEvent->pressure = _bmp3xx->pressure / 100.0F;
    return true;
  }

  /*******************************************************************************/
  /*!
      @brief    Reads a the BMP3XX's altitude sensor into an event.
      @param    altitudeEvent
                Pointer to an adafruit sensor event.
      @returns  True if the sensor event was obtained successfully, False
                otherwise.
  */
  /*******************************************************************************/
  bool getEventAltitude(sensors_event_t *altitudeEvent) {
    if (!_bmp3xx->performReading())
      return false;
    // TODO: update once we add an altitude sensor type
    // see https://github.com/adafruit/Adafruit_Sensor/issues/52
    altitudeEvent->data[0] = _bmp3xx->readAltitude(SEALEVELPRESSURE_HPA);
    return true;
  }

protected:
  Adafruit_BMP3XX *_bmp3xx; ///< BMP3XX  object
};

#endif // WipperSnapper_I2C_Driver_BMP3XX