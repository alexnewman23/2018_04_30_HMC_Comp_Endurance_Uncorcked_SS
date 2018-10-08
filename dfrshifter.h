#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include "HMC_state_machine.h"

#include "DFR_SPI.h"

#ifndef	_DFRSHIFTER_H_
#define _DFRSHIFTER_H_	(1)
//Upshift function
void upshift(void);

//Down shift function
void downshift(void);

//Off Shift Function
void offshift(void);


void test_shifter_algorithm (void);
bool validShift(int target, int RPM);
enum gear get_gear(void);
#endif	// _DFRSHIFTER_H_
