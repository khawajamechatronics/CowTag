/*
 * global_cfg.h
 *
 *  Created on: March 9th, 2017
 *      Author: Steven Hall
 *
 */

#ifndef GLOBAL_CFG_H
#define GLOBAL_CFG_H

// Configuration Options

// Auto generated by script
// Begin auto-generated
// IF YOU CHANGE THE NAME OF THIS DEFINE YOU NEED TO CHANGE THE SEARCH STRING IN
// ../../add_timestamp_to_config.c AS WELL
#define TIMESTAMP_AT_BUILDTIME 1490311160
// End auto-generated

// [0] = Beta
// [1] = Alpha
// [2] = NOT USED
// [3] = Gateway
// Specifies the Tag Type being used
#define TAG_TYPE 0

// Original value: 6
// Specifies the number of retries for send
#define RADIO_SEND_MAX_RETRIES 6

// Original value: 6
// Specifies the number of retries for receive
#define RADIO_RECEIVE_MAX_RETRIES 6

// Original value: (500)
// Specifies the timeout for send and receive in milliseconds
#define RADIO_SEND_ACK_TIMEOUT_TIME_MS (500)

// Original value: (500)
// Specifies the timeout for send and receive in milliseconds
#define RADIO_RECEIVE_ACK_TIMEOUT_TIME_MS (500)

#define HOUR_SLEEP_TICKS 3600000000
#define MINUTE_SLEEP_TICKS 60000000

#define MAX_EEPROM_ADDRESS 0x7FFF
#define MIN_EEPROM_ADDRESS 0x0000

/* DEBUG FLAGS */

/*** Print the contents of the packets to a file ***/
/* verbose_alphaRadioTest also needs to be set to print packets to file */
static const int print_packet_to_file_alpha = 0;

/* verbose_betaRadioTest also needs to be set to print packets to file */
static const int print_packet_to_file_beta = 0;

/* verbose_gatewayRadioTest also needs to be set to print packets to file */
static const int print_packet_to_file_gateway = 0;



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

/*** enable/disable eeprom ***/
static const int usingEeprom = 1;

/*** ignore sensors ***/
static const int ignoreSensors = 1;

#endif // GLOBAL_CFG_H

