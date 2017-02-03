/*
 * eeprom_test.h
 *
 *  Created on: Feb 3, 2017
 *      Author: champ
 */

#ifndef EEPROM_TEST_H_
#define EEPROM_TEST_H_

#include "eeprom.h"

/*constants*/
#define TASKSTACKSIZE		2048	//i2c

/*test prototypes*/
bool eeprom_testStart();
void eeprom_testWriteReadSample();
void eeprom_testValidateMemory();

/**structures*/
Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];

// test runner for the eeprom module
bool eeprom_testStart() {
	// start at beginning of memory addresses
	eeprom_reset();

	// start eeprom thread
	Task_Params taskParams;
	Task_Params_init(&taskParams);
	taskParams.stackSize = TASKSTACKSIZE;
	taskParams.stack = &task0Stack;
	Task_construct(&task0Struct, (Task_FuncPtr)eeprom_testValidateMemory, &taskParams, NULL);

	return true;
}

/*** tests ***/

// Pre-condition:  eeprom address set to 0x0000
// Expects:        18 bytes written and read from eeprom
// Post-condition: 18 bytes stored in eeprom
void eeprom_testWriteReadSample() {
	System_printf("[eeprom_testWriteReadSample]\n");
	System_flush();

	// 18 byte test sample
	uint8_t sample[] = {
			0x11, 0x22, 0x33, 0x44, 0x55,
			0x66, 0x77, 0x88, 0x99, 0xaa,
			0xbb, 0xcc, 0xdd, 0xee, 0xff,
			0x1f, 0x2e, 0x3d
	};

	eeprom_reset();
	eeprom_write(sample, SAMPLE_SIZE);
	eeprom_reset();

	uint8_t received[SAMPLE_SIZE];
	eeprom_readAddress(eeprom_currentAddress >> 8, eeprom_currentAddress & 0xff, SAMPLE_SIZE, received);

	int matches = 0;
	int i;
	for (i = 0; i < SAMPLE_SIZE; i++) {
		if (sample[i] == received[i]) {
			matches++;
		}
	}

	System_printf("write/read matches = %d / 18!\n", matches);
	System_flush();
}

// Pre-condition:  eeprom address set to 0x0000
// Expects:        all eeprom addresses written and read
// Post-condition: eeprom full of test data
void eeprom_testValidateMemory() {
	System_printf("[eeprom_testValidateMemory]\n");
	System_flush();

	// test settings
	uint8_t input[] = { 0x12 };
	uint16_t testsize = 0x00ff;//MAX_EEPROM_ADDRESS;
	uint8_t received[1];

	// tally bad bytes
	unsigned badWrites = 0;
	unsigned badReads = 0;

	// reset memory pointer
	eeprom_reset();

	for (; eeprom_currentAddress < testsize;) {
		// check write
		if (!eeprom_write(input, 1)) {
			badWrites++;
		}

		// check read
		eeprom_readAddress((eeprom_currentAddress - 1) >> 8, (eeprom_currentAddress - 1) & 0xff, 1, received);

		if (received[0] != input[0]) {
			++badReads;
		}
	}

	// count successful writes/reads
	System_printf("Bad Writes = %d / %d\n", badWrites, testsize);
	System_printf("Bad Reads = %d / %d\n", badReads, testsize);
	System_flush();
}


#endif /* EEPROM_TEST_H_ */
