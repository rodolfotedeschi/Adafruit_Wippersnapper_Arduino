/*!
 * @file WipperSnapper_I2C_Driver_BH1745.h
 *
 * Device driver for the BH1745 Color sensor.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Copyright (c) Rodolfo Tedeschi 2023 for Adafruit Industries.
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
#ifndef WipperSnapper_I2C_Driver_BH1745_H
#define WipperSnapper_I2C_Driver_BH1745_H

#include "WipperSnapper_I2C_Driver.h"
#include <BH1745.h>

/**************************************************************************/
/*!
		@brief Class that provides a driver interface for a BH1745 sensor.
*/
/**************************************************************************/
class WipperSnapper_I2C_Driver_BH1745 : public WipperSnapper_I2C_Driver
{
public:
	/*******************************************************************************/
	/*!
			@brief		Constructor for a BH1745 sensor.
			@param		i2c
								The I2C interface.
			@param		sensorAddress
								7-bit device address.
	*/
	/*******************************************************************************/
	WipperSnapper_I2C_Driver_BH1745(TwoWire *i2c, uint16_t sensorAddress)
		: WipperSnapper_I2C_Driver(i2c, sensorAddress)
	{
		_bh1745 = new BH1745(sensorAddress, i2c);
	}

	/*******************************************************************************/
	/*!
			@brief		Destructor for a BH1745 sensor.
	*/
	/*******************************************************************************/
	~WipperSnapper_I2C_Driver_BH1745() { delete _bh1745; }

	/*******************************************************************************/
	/*!
			@brief		Initializes the BH1745 sensor and begins I2C.
			@returns	true if initialized successfully, false otherwise.
	*/
	/*******************************************************************************/
	bool begin() { return _bh1745->begin(); }

	/*******************************************************************************/
	/*!
			@brief		Reads the BH1745 sensor and converts the reading into normalized RGB values.
			@param		colorEvent
								Color sensor reading.
			@returns	true if the sensor event was obtained successfully, false otherwise.
	*/
	/*******************************************************************************/
	bool getEventColor(sensors_event_t *colorEvent) { return _bh1745->getColorEvent(colorEvent); }

	/*******************************************************************************/
	/*!
			@brief		Reads the BH1745 sensor and converts the reading into lux.
			@param		lightEvent
								Light sensor reading, in lux.
			@returns	true if the sensor event was obtained successfully, false otherwise.
	*/
	/*******************************************************************************/
	bool getEventLight(sensors_event_t *lightEvent) { return _bh1745->getLightEvent(lightEvent); }

protected:
	BH1745 *_bh1745; ///< Pointer to BH1745 sensor object
};

#endif // WipperSnapper_I2C_Driver_BH1745_H