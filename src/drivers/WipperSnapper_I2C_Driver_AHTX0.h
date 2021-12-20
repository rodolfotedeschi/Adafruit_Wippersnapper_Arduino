/*!
 * @file WipperSnapper_I2C_Driver_AHTX0.h
 *
 * Device driver for an AHT Humidity and Temperature sensor.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Brent Rubell 2021 for Adafruit Industries.
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */

#ifndef WipperSnapper_I2C_Driver_AHTX0_H
#define WipperSnapper_I2C_Driver_AHTX0_H

#include "WipperSnapper_I2C_Driver.h"
#include <Adafruit_AHTX0.h>

/**************************************************************************/
/*!
    @brief  Class that provides a sensor driver for the AHTX0 temperature
            and humidity sensor.
*/
/**************************************************************************/
class WipperSnapper_I2C_Driver_AHTX0 : public WipperSnapper_I2C_Driver {

public:
  /*******************************************************************************/
  /*!
      @brief    Constructor for an AHTX0 sensor.
      @param    _i2c
                The I2C interface.
      @param    sensorAddress
                The 7-bit I2C address of the AHTX0 sensor.
  */
  /*******************************************************************************/
  WipperSnapper_I2C_Driver_AHTX0(TwoWire *_i2c, uint16_t sensorAddress)
      : WipperSnapper_I2C_Driver(_i2c, sensorAddress) {
    setDriverType(AHTX0); // sets the type of I2C_Driver
    _sensorAddress = sensorAddress;
    _isInitialized = _aht.begin(_i2c);
  }

  /*******************************************************************************/
  /*!
      @brief    Destructor for an AHTX0 sensor.
  */
  /*******************************************************************************/
  ~WipperSnapper_I2C_Driver_AHTX0() {
    _aht_temp = NULL;
    _tempSensorPeriod = 0L;
    _aht_humidity = NULL;
    _humidSensorPeriod = 0L;
    setDriverType(UNSPECIFIED);
  }

  /*******************************************************************************/
  /*!
      @brief    Enables the AHTX0's temperature sensor.
  */
  /*******************************************************************************/
  void enableSensorAmbientTemperature() {
    _aht_temp = _aht.getSensorAmbientTemperatureeratureSensor();
  }

  /*******************************************************************************/
  /*!
      @brief    Enables the AHTX0's humidity sensor.
  */
  /*******************************************************************************/
  void enableSensorRelativeHumidity() {
    _aht_humidity = _aht.getSensorRelativeHumidityitySensor();
  }

  /*******************************************************************************/
  /*!
      @brief    Disables the AHTX0's temperature sensor.
  */
  /*******************************************************************************/
  void disableSensorAmbientTemperature() {
    _aht_temp = NULL; // TODO: change to nullptr instead!
    _tempSensorPeriod = 0L;
  }

  /*******************************************************************************/
  /*!
      @brief    Disables the AHTX0's humidity sensor.
  */
  /*******************************************************************************/
  void disableSensorRelativeHumidity() {
    _aht_humidity = NULL;  // TODO: change to nullptr instead!
    _humidSensorPeriod = 0L;
  }

  /*******************************************************************************/
  /*!
      @brief    Updates the properties of an ambient temperature
                  sensor, provided sensor_period.
      @param    tempPeriod
                Sensor's period.
  */
  /*******************************************************************************/
  void updateSensorAmbientTemperature(float tempPeriod) {
      // disable the sensor
      if (tempPeriod == 0)
        disableSensorAmbientTemperature();
      // enable a previously disabled sensor
      if (tempPeriod > 0 && _aht_temp == NULL)
        enableSensorAmbientTemperature();

      setSensorAmbientTemperaturePeriod(tempPeriod);
   }

  /*******************************************************************************/
  /*!
      @brief    Gets the AHTX0's current temperature.
      @param    tempEvent
                Pointer to an Adafruit_Sensor event.
      @returns  True if the temperature was obtained successfully, False
                otherwise.
  */
  /*******************************************************************************/
  bool getSensorAmbientTemperature(sensors_event_t *tempEvent) {
    // update temp, if sensor enabled
    if (_aht_temp != NULL) {
      _aht_temp->getEvent(tempEvent);
      return true;
    }
    return false;
  }

  /*******************************************************************************/
  /*!
      @brief    Gets the AHTX0's current humidity.
      @param    humidEvent
                Pointer to an Adafruit_Sensor event.
      @returns  True if the humidity was obtained successfully, False
                otherwise.
  */
  /*******************************************************************************/
  bool getSensorRelativeHumidity(sensors_event_t *humidEvent) {
    // update humidity, if sensor enabled
    if (_aht_humidity != NULL) {
      _aht_humidity->getEvent(humidEvent);
      return true;
    }
    return false;
  }

protected:
  Adafruit_AHTX0 _aht; ///< AHTX0 driver object
  Adafruit_Sensor *_aht_temp =
      NULL; ///< Holds data for the AHTX0's temperature sensor
  Adafruit_Sensor *_aht_humidity =
      NULL; ///< Holds data for the AHTX0's humidity sensor
};

#endif // WipperSnapper_I2C_Driver_AHTX0