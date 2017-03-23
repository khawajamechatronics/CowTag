/*
 * debug.h
 *
 *  Created on: Nov 8, 2016
 *      Author: annik
 */

#ifndef DEBUG_H_
#define DEBUG_H_

/*** verbose for printing debug messages trough different threads/Functions ***/
static const int verbose_main = 1;

/* sensor blocks */
static const int verbose_sensors = 0;
static const int verbose_i2c = 0;

/* Serialization of sensor packets */
static const int verbose_serialize = 0;

/* EEPROM */
static const int verbose_eeprom = 0;

/* Arduino Communications */
static const int verbose_arduinoCom = 0;

/* Alpha send and receive radio */
static const int verbose_alphaRadio = 1;

/* Tests suites */
static const int verbose_serializeTest = 0;
static const int verbose_betaRadioTest = 1;
static const int verbose_alphaRadioTest = 1;
static const int verbose_gatewayRadioTest = 1;
static const int verbose_arduinoComTest = 0;
static const int verbose_eepromTest = 1;

// Timestamp
static const int verbose_timestamp = 0;
static const int verbose_uptime = 0;

// Sleep output
static const int verbose_sleep = 0;

/*** ignore sensors ***/
static const int ignoreSensors = 1;


#endif /* DEBUG_H_ */
